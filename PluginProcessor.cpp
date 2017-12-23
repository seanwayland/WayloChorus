/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
C74GenAudioProcessor::C74GenAudioProcessor()
:m_CurrentBufferSize(0)
{
	// use a default samplerate and vector size here, reset it later
	m_C74PluginState = (CommonState *)C74_GENPLUGIN::create(44100, 64);
	C74_GENPLUGIN::reset(m_C74PluginState);

	m_InputBuffers = new t_sample *[C74_GENPLUGIN::num_inputs()];
	m_OutputBuffers = new t_sample *[C74_GENPLUGIN::num_outputs()];
	
	for (int i = 0; i < C74_GENPLUGIN::num_inputs(); i++) {
		m_InputBuffers[i] = NULL;
	}
	for (int i = 0; i < C74_GENPLUGIN::num_outputs(); i++) {
		m_OutputBuffers[i] = NULL;
	}

}

C74GenAudioProcessor::~C74GenAudioProcessor()
{
	C74_GENPLUGIN::destroy(m_C74PluginState);
}

//==============================================================================
const String C74GenAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int C74GenAudioProcessor::getNumParameters()
{
	return C74_GENPLUGIN::num_params();
}

float C74GenAudioProcessor::getParameter (int index)
{
	t_param value;
	t_param min = C74_GENPLUGIN::getparametermin(m_C74PluginState, index);
	t_param range = fabs(C74_GENPLUGIN::getparametermax(m_C74PluginState, index) - min);
	
	C74_GENPLUGIN::getparameter(m_C74PluginState, index, &value);
	
	value = (value - min) / range;
	
	return value;
}

void C74GenAudioProcessor::setParameter (int index, float newValue)
{
	t_param min = C74_GENPLUGIN::getparametermin(m_C74PluginState, index);
	t_param range = fabs(C74_GENPLUGIN::getparametermax(m_C74PluginState, index) - min);
	t_param value = newValue * range + min;
	
	C74_GENPLUGIN::setparameter(m_C74PluginState, index, value, NULL);
}

const String C74GenAudioProcessor::getParameterName (int index)
{
    return String(C74_GENPLUGIN::getparametername(m_C74PluginState, index));
}

const String C74GenAudioProcessor::getParameterText (int index)
{
	String text = String(getParameter(index));
	text += String(" ");
	text += String(C74_GENPLUGIN::getparameterunits(m_C74PluginState, index));

	return text;
}

const String C74GenAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String C74GenAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool C74GenAudioProcessor::isInputChannelStereoPair (int index) const
{
    return C74_GENPLUGIN::num_inputs() == 2;
}

bool C74GenAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return C74_GENPLUGIN::num_outputs() == 2;
}

bool C74GenAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool C74GenAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool C74GenAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double C74GenAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int C74GenAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int C74GenAudioProcessor::getCurrentProgram()
{
    return 0;
}

void C74GenAudioProcessor::setCurrentProgram (int index)
{
}

const String C74GenAudioProcessor::getProgramName (int index)
{
    return String();
}

void C74GenAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void C74GenAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	
	// initialize samplerate and vectorsize with the correct values
	m_C74PluginState->sr = sampleRate;
	m_C74PluginState->vs = samplesPerBlock;

	assureBufferSize(samplesPerBlock);
}

void C74GenAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void C74GenAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	assureBufferSize(buffer.getNumSamples());
	
	// fill input buffers
	for (int i = 0; i < C74_GENPLUGIN::num_inputs(); i++) {
		if (i < getNumInputChannels()) {
			for (int j = 0; j < m_CurrentBufferSize; j++) {
				m_InputBuffers[i][j] = buffer.getReadPointer(i)[j];
			}
		} else {
			memset(m_InputBuffers[i], 0, m_CurrentBufferSize *  sizeof(double));
		}
	}
	
	// process audio
	C74_GENPLUGIN::perform(m_C74PluginState,
								  m_InputBuffers,
								  C74_GENPLUGIN::num_inputs(),
								  m_OutputBuffers,
								  C74_GENPLUGIN::num_outputs(),
								  buffer.getNumSamples());

	// fill output buffers
	for (int i = 0; i < getNumOutputChannels(); i++) {
		if (i < C74_GENPLUGIN::num_outputs()) {
			for (int j = 0; j < buffer.getNumSamples(); j++) {
				buffer.getWritePointer(i)[j] = m_OutputBuffers[i][j];
			}
		} else {
			buffer.clear (i, 0, buffer.getNumSamples());
		}
	}
}

//==============================================================================
bool C74GenAudioProcessor::hasEditor() const
{
    return true; // (change this to true if you choose to supply an editor)
}

AudioProcessorEditor* C74GenAudioProcessor::createEditor()
{
    return new C74GenAudioProcessorEditor (*this);
}

//==============================================================================
void C74GenAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
//    ScopedPointer<XmlElement> xml (C74_GENPLUGIN::getparameters().state.createXml());
 //   copyXmlToBinary (*xml, destData);
	//code from MAX
    char *state;
	size_t statesize = C74_GENPLUGIN::getstatesize(m_C74PluginState);
	state = (char *)malloc(sizeof(char) * statesize);
	
	C74_GENPLUGIN::getstate(m_C74PluginState, state);
	destData.replaceWith(state, sizeof(char) * statesize);

	if (state) free(state);
 

}

void C74GenAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
	C74_GENPLUGIN::setstate(m_C74PluginState, (const char *)data);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new C74GenAudioProcessor();
}

//==============================================================================
// C74 added methods

void C74GenAudioProcessor::assureBufferSize(long bufferSize)
{
	if (bufferSize > m_CurrentBufferSize) {
		for (int i = 0; i < C74_GENPLUGIN::num_inputs(); i++) {
			if (m_InputBuffers[i]) delete m_InputBuffers[i];
			m_InputBuffers[i] = new t_sample[bufferSize];
		}
		for (int i = 0; i < C74_GENPLUGIN::num_outputs(); i++) {
			if (m_OutputBuffers[i]) delete m_OutputBuffers[i];
			m_OutputBuffers[i] = new t_sample[bufferSize];
		}
		
		m_CurrentBufferSize = bufferSize;
	}
}
