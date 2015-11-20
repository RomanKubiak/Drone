/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/


#include "MainComponent.h"
const float DENORMAL_THRESH = 1e-6f;

    //==============================================================================
MainComponent::MainComponent() : timeInSamples(0), ui(*this)
{
    setSize (800, 600);
    addAndMakeVisible(&ui);
    setAudioChannels (0, 1);
    noiseLevelAR.setAllTimes(0.0f, 0.2f, 0.0f, 0.0f);
    oscFreqAR.setAllTimes(0.001f, 0.2f, 0.001f, 0.001f);
    noiseLevel = 0.5f;
    oscBaseFreq = 50.0f;
    oscType = Sin;
    distGainIndB = 0.5f;
    distortionType = hardClipping;
    oscSin.setFrequency(oscBaseFreq);
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    sRate = sampleRate;
    stk::Stk::setSampleRate(sampleRate);
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    float oscSample, noiseSample, oscARFreqSample, oscARLevelSample, noiseARLevelSample, mixSample;
    for (int i=0; i<bufferToFill.numSamples; i++)
    {
        switch (oscType)
        {
            case Saw:
                oscSaw.setFrequency(jmax<float>(1, oscFreqAR.tick() * oscBaseFreq));
                oscSample = oscSaw.tick();
                break;
            case Sin:
                oscSin.setFrequency(oscFreqAR.tick() * oscBaseFreq);
                oscSample = oscSin.tick();
                break;
            case Square:
                oscSquare.setFrequency(jmax<float>(1, oscFreqAR.tick() * oscBaseFreq));
                oscSample = oscSquare.tick();
                break;
            default:
                break;
        }

        // mixSample = (noiseSample + oscSample) - (noiseSample * oscSample);
        mixSample = oscSample;
        if (doWaveshape)
            mixSample = waveshape(mixSample);

        bufferToFill.buffer->addSample(0, bufferToFill.startSample+i, mixSample);
    }

    processDistortion(*bufferToFill.buffer);
    bufferToFill.buffer->applyGain(0.2f);

    timeInSamples += bufferToFill.numSamples;

    if (timeInSamples >= sRate)
    {
        oscFreqAR.keyOff();
        oscLevelAR.keyOff();
        noiseLevelAR.keyOff();

        oscFreqAR.keyOn();
        oscLevelAR.keyOn();
        noiseLevelAR.keyOn();
        timeInSamples = 0;
    }
}

float MainComponent::waveshape(float in)
{
    if(in <= -1.25f)
    {
        return -0.984375;
    }
    else if(in >= 1.25f)
    {
        return 0.984375;
    }
    else
    {
        return 1.1f * in - 0.2f * in * in * in;
    }
}

void MainComponent::releaseResources()
{
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void MainComponent::resized()
{
    ui.setBounds(0,0,getWidth(),getHeight());
}

void MainComponent::setOscFreqAR(float a, float r)
{
    ScopedWriteLock swl(audioLock);
    oscFreqAR.setAllTimes(a, r, 0.0f, 0.0f);
}

void MainComponent::setOscLevelAR(float a, float r)
{
    ScopedWriteLock swl(audioLock);
    oscLevelAR.setAllTimes(a, r, 0.0f, 0.0f);
}

void MainComponent::setNoiseLevelAR(float a, float r)
{
    ScopedWriteLock swl(audioLock);
    oscLevelAR.setAllTimes(a, r, 0.0f, 0.0f);
}

void MainComponent::setNoiseLevel(float level)
{
}

void MainComponent::setOscFreq(float f)
{
    ScopedWriteLock swl(audioLock);
    oscBaseFreq = f;
}

void MainComponent::setOscShape(uint8_t shape)
{
    ScopedWriteLock swl(audioLock);

    oscType = (OscType)shape;
}

void MainComponent::setWaveshape(bool _doWaveshape)
{
    ScopedWriteLock swl(audioLock);

    doWaveshape = _doWaveshape;
}

void MainComponent::setDistortionType(uint8_t type)
{
    ScopedWriteLock swl(audioLock);
    distortionType = (DistType)type;
}

void MainComponent::processDistortion(AudioSampleBuffer &buffer)
{
    float gain = powf(10.0f, distGainIndB/20.f);

    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        // Apply gain
        buffer.applyGain(channel, 0, buffer.getNumSamples(), gain);

        // Put track audio data into _currentTrackBuffer
        float * originalData = new float;
        originalData = buffer.getWritePointer(channel);

        // Apply distortion (sample per sample)
        switch (distortionType) {
            case hardClipping:
            {
                float threshold = 0.5f;
                for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
                {
                    if(originalData[sample]  > threshold) // positive hard clipping
                    {
                        originalData[sample] = threshold;
                    }
                    else
                    {
                        if(originalData[sample]  < - threshold) // negative hard clipping
                        {
                            originalData[sample] = - threshold;
                        }
                    }
                }
                break;
            }

            case softClipping:
            {
                float threshold1 = 1.0f/3.0f;
                float threshold2 = 2.0f/3.0f;
                for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
                {
                    if(originalData[sample]  > threshold1)
                    {
                        if(originalData[sample] > threshold2) // positive clipping
                        {
                            originalData[sample] = 1.0f;
                        }
                        else // soft knee (positive)
                        {
                            originalData[sample] = (3.0f - (2.0f - 3.0f*originalData[sample])*(2.0f - 3.0f*originalData[sample]))/3.0f;
                        }
                    }
                    else
                    {
                        if(originalData[sample]  < -threshold1)
                        {
                            if(originalData[sample] < -threshold2) // negative clipping
                            {
                                originalData[sample] = -1.0f;
                            }
                            else // soft knee (negative)
                            {
                                originalData[sample] = - (3.0f - (2.0f + 3.0f*originalData[sample])*(2.0f + 3.0f*originalData[sample]))/3.0f;
                            }
                        }
                        else // linear region (-1/3..1/3)
                        {
                            originalData[sample] *= 2.0f;
                        }
                    }

                    originalData[sample] /= 2.0f; // divide all by 2 to compensate for extra 6 dB gain boost
                }
                break;
            }

            case softClippingExp:
            {
                for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
                {
                    if (originalData[sample] > 0.0f) // positive
                    {
                        originalData[sample] = 1.0f - expf(-originalData[sample]);
                    }
                    else // negative
                    {
                        originalData[sample] = - 1.0f + expf(originalData[sample]);
                    }
                }
                break;
            }

            case fullWaveRectifier:
            {
                for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
                {
                    originalData[sample] = fabs(originalData[sample]);
                }
                break;
            }

            case halfWaveRectifier:
            {
                for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
                {
                    originalData[sample] = 0.5f*(fabs(originalData[sample])+originalData[sample]);
                }
                break;
            }

            default:
                break;
        }
    }
}
Component* createMainContentComponent()     { return new MainComponent(); }
