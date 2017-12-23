/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class C74GenAudioProcessorEditor  : public AudioProcessorEditor,
                                    public Slider::Listener
{
public:
    C74GenAudioProcessorEditor (C74GenAudioProcessor&);
    ~C74GenAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    //AudioProcessorValueTreeState& valueTreeState;
    C74GenAudioProcessor& processor;
    ScopedPointer<Slider> d1LevelSlider;
    ScopedPointer<Label> d1Level;
    ScopedPointer<Slider> d1freqSlider;
    ScopedPointer<Slider> d1timeSlider;
    ScopedPointer<Label> d1time;
    ScopedPointer<Label> d1freq;
    ScopedPointer<Slider> d2LevelSlider;
    ScopedPointer<Label> d2Level;
    ScopedPointer<Slider> d2freqSlider;
    
    ScopedPointer<Label> d2time;
    ScopedPointer<Label> d2freq;
    ScopedPointer<Slider> d2timeSlider;
    ScopedPointer<Slider> d3LevelSlider;
    ScopedPointer<Label> d3Level;
    ScopedPointer<Slider> d3freqSlider;
    
    ScopedPointer<Label> d3time;
    ScopedPointer<Label> d3freq;
    ScopedPointer<Slider> d4LevelSlider;
    ScopedPointer<Label> d4Level;
    ScopedPointer<Slider> d4freqSlider;
    
    ScopedPointer<Label> d4time;
    ScopedPointer<Label> d4freq;
    ScopedPointer<Slider> d3timeSlider;
    
    ScopedPointer<Slider> d5LevelSlider;
    ScopedPointer<Label> d5Level;
    ScopedPointer<Slider> d5freqSlider;
    
    ScopedPointer<Label> d5time;
    ScopedPointer<Label> d5freq;
    ScopedPointer<Slider> d6LevelSlider;
    ScopedPointer<Label> d6Level;
    ScopedPointer<Slider> d6freqSlider;
    
    ScopedPointer<Label> d6time;
    ScopedPointer<Label> d6freq;
    ScopedPointer<Slider> d5timeSlider;
    ScopedPointer<Slider> d6timeSlider;
    ScopedPointer<Slider> d7LevelSlider;
    ScopedPointer<Label> d7Level;
    ScopedPointer<Slider> d7freqSlider;
    
    ScopedPointer<Label> d7time;
    ScopedPointer<Label> d7freq;
    ScopedPointer<Slider> d8LevelSlider;
    ScopedPointer<Label> d8Level;
    ScopedPointer<Slider> d8freqSlider;
    
    ScopedPointer<Label> d8time;
    ScopedPointer<Label> d8freq;
    ScopedPointer<Slider> d7timeSlider;
    
    ScopedPointer<Label> label;
    ScopedPointer<Slider> d4timeSlider;
    ScopedPointer<Slider> d8timeSlider;
    ScopedPointer<Slider> directLevelSlider;
    ScopedPointer<Label> directLevel;
    ScopedPointer<Slider> moddepthSlider;
    ScopedPointer<Label> moddepth;
    ScopedPointer<Slider> d5FdBkSlider;
    ScopedPointer<Label> d5FdBk;
    ScopedPointer<Slider> d6FdBkSlider;
    ScopedPointer<Label> d6FdBk;
    ScopedPointer<Slider> d7FdBkSlider;
    ScopedPointer<Label> d7FdBk;
    ScopedPointer<Slider> d8FdBkSlider;
    ScopedPointer<Label> d8FdBk;
    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (C74GenAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
