/*
  ==============================================================================

    MaxFilter.h
    Created: 26 Nov 2015 6:10:22pm
    Author:  r.kubiak

  ==============================================================================
*/

#ifndef MAXFILTER_H_INCLUDED
#define MAXFILTER_H_INCLUDED

#ifndef MAXPI
#define MAXPI  3.1415926535897932384626433832795
#endif
#define MAXTWOPI 6.283185307179586476925286766559

#define TW

#include "JuceHeader.h"

class maxiFilter {
	double gain;
	double input;
	double output;
	double inputs[10];
	double outputs[10];
	double cutoff1;
	double x;//speed
	double y;//pos
	double z;//pole
	double c;//filter coefficient

public:
	maxiFilter():x(0.0), y(0.0), z(0.0), c(0.0){};
	double cutoff;
	double resonance;
	double lores(double input,double cutoff1, double resonance);
	double hires(double input,double cutoff1, double resonance);
	double bandpass(double input,double cutoff1, double resonance);
	double lopass(double input,double cutoff);
	double hipass(double input,double cutoff);
	double sampleRate;

};


#endif  // MAXFILTER_H_INCLUDED
