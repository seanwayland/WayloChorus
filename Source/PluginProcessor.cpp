/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
WayloChorus6AudioProcessor::WayloChorus6AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

WayloChorus6AudioProcessor::~WayloChorus6AudioProcessor()
{
}

//==============================================================================
const String WayloChorus6AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WayloChorus6AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WayloChorus6AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WayloChorus6AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double WayloChorus6AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WayloChorus6AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WayloChorus6AudioProcessor::getCurrentProgram()
{
    return 0;
}

void WayloChorus6AudioProcessor::setCurrentProgram (int index)
{
}

const String WayloChorus6AudioProcessor::getProgramName (int index)
{
    return {};
}

void WayloChorus6AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void WayloChorus6AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    pyo.setup(getTotalNumOutputChannels(), samplesPerBlock, sampleRate);
    pyo.exec(BinaryData::stereoDelay_py);
}

void WayloChorus6AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WayloChorus6AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void WayloChorus6AudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    //ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();



    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    //for (int channel = 0; channel < totalNumInputChannels; ++channel)
    //{
      pyo.process(buffer);

        // ..do something to the data...
   // }
}

//==============================================================================
bool WayloChorus6AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* WayloChorus6AudioProcessor::createEditor()
{
    return new WayloChorus6AudioProcessorEditor (*this);
}

//==============================================================================
void WayloChorus6AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void WayloChorus6AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WayloChorus6AudioProcessor();
}
