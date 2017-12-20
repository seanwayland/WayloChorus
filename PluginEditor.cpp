/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
C74GenAudioProcessorEditor::C74GenAudioProcessorEditor (C74GenAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (d1LevelSlider = new Slider ("d1LevelSlider"));
    d1LevelSlider->setRange (0, 10, 0.001);
    d1LevelSlider->setSliderStyle (Slider::LinearHorizontal);
    d1LevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d1LevelSlider->addListener (this);

    addAndMakeVisible (d1Level = new Label ("d1Level",
                                            TRANS("d1 Level\n")));
    d1Level->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d1Level->setJustificationType (Justification::centredLeft);
    d1Level->setEditable (false, false, false);
    d1Level->setColour (TextEditor::textColourId, Colours::black);
    d1Level->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d1freqSlider = new Slider ("d1freqSlider"));
    d1freqSlider->setRange (0, 10, 0.001);
    d1freqSlider->setSliderStyle (Slider::LinearHorizontal);
    d1freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d1freqSlider->addListener (this);

    addAndMakeVisible (d1timeSlider = new Slider ("d1timeSlider"));
    d1timeSlider->setRange (0, 10, 0.001);
    d1timeSlider->setSliderStyle (Slider::LinearHorizontal);
    d1timeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d1timeSlider->addListener (this);

    addAndMakeVisible (d1time = new Label ("d1time",
                                           TRANS("d1 Time")));
    d1time->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d1time->setJustificationType (Justification::centredLeft);
    d1time->setEditable (false, false, false);
    d1time->setColour (TextEditor::textColourId, Colours::black);
    d1time->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d1freq = new Label ("d1freq",
                                           TRANS("d1 Freq\n")));
    d1freq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d1freq->setJustificationType (Justification::centredLeft);
    d1freq->setEditable (false, false, false);
    d1freq->setColour (TextEditor::textColourId, Colours::black);
    d1freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d2LevelSlider = new Slider ("d2LevelSlider"));
    d2LevelSlider->setRange (0, 10, 0.001);
    d2LevelSlider->setSliderStyle (Slider::LinearHorizontal);
    d2LevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d2LevelSlider->addListener (this);

    addAndMakeVisible (d2Level = new Label ("d2Level",
                                            TRANS("d2 Level\n")));
    d2Level->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d2Level->setJustificationType (Justification::centredLeft);
    d2Level->setEditable (false, false, false);
    d2Level->setColour (TextEditor::textColourId, Colours::black);
    d2Level->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d2freqSlider = new Slider ("d2freqSlider"));
    d2freqSlider->setRange (0, 10, 0.001);
    d2freqSlider->setSliderStyle (Slider::LinearHorizontal);
    d2freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d2freqSlider->addListener (this);



    addAndMakeVisible (d2time = new Label ("d2time",
                                           TRANS("d2 Time")));
    d2time->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d2time->setJustificationType (Justification::centredLeft);
    d2time->setEditable (false, false, false);
    d2time->setColour (TextEditor::textColourId, Colours::black);
    d2time->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d2freq = new Label ("d2freq",
                                           TRANS("d2 Freq\n")));
    d2freq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d2freq->setJustificationType (Justification::centredLeft);
    d2freq->setEditable (false, false, false);
    d2freq->setColour (TextEditor::textColourId, Colours::black);
    d2freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d2timeSlider = new Slider ("d2timeSlider"));
    d2timeSlider->setRange (0, 10, 0.001);
    d2timeSlider->setSliderStyle (Slider::LinearHorizontal);
    d2timeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d2timeSlider->addListener (this);

    addAndMakeVisible (d3LevelSlider = new Slider ("d3LevelSlider"));
    d3LevelSlider->setRange (0, 10, 0.001);
    d3LevelSlider->setSliderStyle (Slider::LinearHorizontal);
    d3LevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d3LevelSlider->addListener (this);

    addAndMakeVisible (d3Level = new Label ("d3Level",
                                            TRANS("d3 Level\n")));
    d3Level->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d3Level->setJustificationType (Justification::centredLeft);
    d3Level->setEditable (false, false, false);
    d3Level->setColour (TextEditor::textColourId, Colours::black);
    d3Level->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d3freqSlider = new Slider ("d3freqSlider"));
    d3freqSlider->setRange (0, 10, 0.001);
    d3freqSlider->setSliderStyle (Slider::LinearHorizontal);
    d3freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d3freqSlider->addListener (this);


    addAndMakeVisible (d3time = new Label ("d3time",
                                           TRANS("d3 Time")));
    d3time->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d3time->setJustificationType (Justification::centredLeft);
    d3time->setEditable (false, false, false);
    d3time->setColour (TextEditor::textColourId, Colours::black);
    d3time->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d3freq = new Label ("d3freq",
                                           TRANS("d3 Freq\n")));
    d3freq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d3freq->setJustificationType (Justification::centredLeft);
    d3freq->setEditable (false, false, false);
    d3freq->setColour (TextEditor::textColourId, Colours::black);
    d3freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d4LevelSlider = new Slider ("d4LevelSlider"));
    d4LevelSlider->setRange (0, 10, 0.001);
    d4LevelSlider->setSliderStyle (Slider::LinearHorizontal);
    d4LevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d4LevelSlider->addListener (this);

    addAndMakeVisible (d4Level = new Label ("d4Level",
                                            TRANS("d4 Level\n")));
    d4Level->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d4Level->setJustificationType (Justification::centredLeft);
    d4Level->setEditable (false, false, false);
    d4Level->setColour (TextEditor::textColourId, Colours::black);
    d4Level->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d4freqSlider = new Slider ("d4freqSlider"));
    d4freqSlider->setRange (0, 10, 0.001);
    d4freqSlider->setSliderStyle (Slider::LinearHorizontal);
    d4freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d4freqSlider->addListener (this);



    addAndMakeVisible (d4time = new Label ("d4time",
                                           TRANS("d4 Time")));
    d4time->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d4time->setJustificationType (Justification::centredLeft);
    d4time->setEditable (false, false, false);
    d4time->setColour (TextEditor::textColourId, Colours::black);
    d4time->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d4freq = new Label ("d4freq",
                                           TRANS("d4 Freq\n")));
    d4freq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d4freq->setJustificationType (Justification::centredLeft);
    d4freq->setEditable (false, false, false);
    d4freq->setColour (TextEditor::textColourId, Colours::black);
    d4freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d3timeSlider = new Slider ("d3timeSlider"));
    d3timeSlider->setRange (0, 10, 0.001);
    d3timeSlider->setSliderStyle (Slider::LinearHorizontal);
    d3timeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d3timeSlider->addListener (this);



    addAndMakeVisible (d5LevelSlider = new Slider ("d5LevelSlider"));
    d5LevelSlider->setRange (0, 10, 0.001);
    d5LevelSlider->setSliderStyle (Slider::LinearHorizontal);
    d5LevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d5LevelSlider->addListener (this);

    addAndMakeVisible (d5Level = new Label ("d5Level",
                                            TRANS("d5 level\n")));
    d5Level->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d5Level->setJustificationType (Justification::centredLeft);
    d5Level->setEditable (false, false, false);
    d5Level->setColour (TextEditor::textColourId, Colours::black);
    d5Level->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d5freqSlider = new Slider ("d5freqSlider"));
    d5freqSlider->setRange (0, 10, 0.001);
    d5freqSlider->setSliderStyle (Slider::LinearHorizontal);
    d5freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d5freqSlider->addListener (this);



    addAndMakeVisible (d5time = new Label ("d5time",
                                           TRANS("d5 Time")));
    d5time->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d5time->setJustificationType (Justification::centredLeft);
    d5time->setEditable (false, false, false);
    d5time->setColour (TextEditor::textColourId, Colours::black);
    d5time->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d5freq = new Label ("d5freq",
                                           TRANS("d5 Freq\n")));
    d5freq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d5freq->setJustificationType (Justification::centredLeft);
    d5freq->setEditable (false, false, false);
    d5freq->setColour (TextEditor::textColourId, Colours::black);
    d5freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d6LevelSlider = new Slider ("d6LevelSlider"));
    d6LevelSlider->setRange (0, 10, 0.001);
    d6LevelSlider->setSliderStyle (Slider::LinearHorizontal);
    d6LevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d6LevelSlider->addListener (this);

    addAndMakeVisible (d6Level = new Label ("d6Level",
                                            TRANS("d6 Level\n")));
    d6Level->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d6Level->setJustificationType (Justification::centredLeft);
    d6Level->setEditable (false, false, false);
    d6Level->setColour (TextEditor::textColourId, Colours::black);
    d6Level->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d6freqSlider = new Slider ("d6freqSlider"));
    d6freqSlider->setRange (0, 10, 0.001);
    d6freqSlider->setSliderStyle (Slider::LinearHorizontal);
    d6freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d6freqSlider->addListener (this);



    addAndMakeVisible (d6time = new Label ("d6time",
                                           TRANS("d6 Time")));
    d6time->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d6time->setJustificationType (Justification::centredLeft);
    d6time->setEditable (false, false, false);
    d6time->setColour (TextEditor::textColourId, Colours::black);
    d6time->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d6freq = new Label ("d6freq",
                                           TRANS("d6 Freq\n")));
    d6freq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d6freq->setJustificationType (Justification::centredLeft);
    d6freq->setEditable (false, false, false);
    d6freq->setColour (TextEditor::textColourId, Colours::black);
    d6freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d5timeSlider = new Slider ("d5timeSlider"));
    d5timeSlider->setRange (0, 10, 0.001);
    d5timeSlider->setSliderStyle (Slider::LinearHorizontal);
    d5timeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d5timeSlider->addListener (this);

    addAndMakeVisible (d6timeSlider = new Slider ("d6timeSlider"));
    d6timeSlider->setRange (0, 10, 0.001);
    d6timeSlider->setSliderStyle (Slider::LinearHorizontal);
    d6timeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d6timeSlider->addListener (this);

    addAndMakeVisible (d7LevelSlider = new Slider ("d7LevelSlider"));
    d7LevelSlider->setRange (0, 10, 0.001);
    d7LevelSlider->setSliderStyle (Slider::LinearHorizontal);
    d7LevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d7LevelSlider->addListener (this);

    addAndMakeVisible (d7Level = new Label ("d7Level",
                                            TRANS("d7 Level\n"
                                            "\n")));
    d7Level->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d7Level->setJustificationType (Justification::centredLeft);
    d7Level->setEditable (false, false, false);
    d7Level->setColour (TextEditor::textColourId, Colours::black);
    d7Level->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d7freqSlider = new Slider ("d7freqSlider"));
    d7freqSlider->setRange (0, 10, 0.001);
    d7freqSlider->setSliderStyle (Slider::LinearHorizontal);
    d7freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d7freqSlider->addListener (this);

 

    addAndMakeVisible (d7time = new Label ("d7time",
                                           TRANS("d7 Time")));
    d7time->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d7time->setJustificationType (Justification::centredLeft);
    d7time->setEditable (false, false, false);
    d7time->setColour (TextEditor::textColourId, Colours::black);
    d7time->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d7freq = new Label ("d7freq",
                                           TRANS("d7 Freq\n")));
    d7freq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d7freq->setJustificationType (Justification::centredLeft);
    d7freq->setEditable (false, false, false);
    d7freq->setColour (TextEditor::textColourId, Colours::black);
    d7freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d8LevelSlider = new Slider ("d8LevelSlider"));
    d8LevelSlider->setRange (0, 10, 0.001);
    d8LevelSlider->setSliderStyle (Slider::LinearHorizontal);
    d8LevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d8LevelSlider->addListener (this);

    addAndMakeVisible (d8Level = new Label ("d8Level",
                                            TRANS("d8 Level\n")));
    d8Level->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d8Level->setJustificationType (Justification::centredLeft);
    d8Level->setEditable (false, false, false);
    d8Level->setColour (TextEditor::textColourId, Colours::black);
    d8Level->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d8freqSlider = new Slider ("d8freqSlider"));
    d8freqSlider->setRange (0, 10, 0.001);
    d8freqSlider->setSliderStyle (Slider::LinearHorizontal);
    d8freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d8freqSlider->addListener (this);



    addAndMakeVisible (d8time = new Label ("d8time",
                                           TRANS("d8 Time")));
    d8time->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d8time->setJustificationType (Justification::centredLeft);
    d8time->setEditable (false, false, false);
    d8time->setColour (TextEditor::textColourId, Colours::black);
    d8time->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d8freq = new Label ("d8freq",
                                           TRANS("d8 Freq\n")));
    d8freq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    d8freq->setJustificationType (Justification::centredLeft);
    d8freq->setEditable (false, false, false);
    d8freq->setColour (TextEditor::textColourId, Colours::black);
    d8freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d7timeSlider = new Slider ("d7timeSlider"));
    d7timeSlider->setRange (0, 10, 0.001);
    d7timeSlider->setSliderStyle (Slider::LinearHorizontal);
    d7timeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d7timeSlider->addListener (this);



    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("WAYLOMODELAY  \n"
                                          "www.seanwayland.com\n")));
    label->setFont (Font ("Copperplate", 40.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::yellow);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (d4timeSlider = new Slider ("d4timeSlider"));
    d4timeSlider->setRange (0, 10, 0.001);
    d4timeSlider->setSliderStyle (Slider::LinearHorizontal);
    d4timeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d4timeSlider->addListener (this);

    addAndMakeVisible (d8timeSlider = new Slider ("d8timeSlider"));
    d8timeSlider->setRange (0, 10, 0.001);
    d8timeSlider->setSliderStyle (Slider::LinearHorizontal);
    d8timeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    d8timeSlider->addListener (this);

    addAndMakeVisible (directLevelSlider = new Slider ("directLevelSlider"));
    directLevelSlider->setRange (0, 10, 0.001);
    directLevelSlider->setSliderStyle (Slider::LinearHorizontal);
    directLevelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    directLevelSlider->addListener (this);

    addAndMakeVisible (directLevel = new Label ("directLevel",
                                                TRANS("Direct Level")));
    directLevel->setFont (Font (16.00f, Font::plain).withTypefaceStyle ("Regular"));
    directLevel->setJustificationType (Justification::centredLeft);
    directLevel->setEditable (false, false, false);
    directLevel->setColour (TextEditor::textColourId, Colours::black);
    directLevel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (moddepthSlider = new Slider ("moddepthSlider"));
    moddepthSlider->setRange (0, 10, 0.001);
    moddepthSlider->setSliderStyle (Slider::LinearHorizontal);
    moddepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    moddepthSlider->addListener (this);

    addAndMakeVisible (moddepth = new Label ("moddepth",
                                             TRANS("Mod Depth\n")));
    moddepth->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    moddepth->setJustificationType (Justification::centredLeft);
    moddepth->setEditable (false, false, false);
    moddepth->setColour (TextEditor::textColourId, Colours::black);
    moddepth->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 700);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

C74GenAudioProcessorEditor::~C74GenAudioProcessorEditor()
{
   //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    d1LevelSlider = nullptr;
    d1Level = nullptr;
    d1freqSlider = nullptr;
    d1timeSlider = nullptr;
    d1time = nullptr;
    d1freq = nullptr;
    d2LevelSlider = nullptr;
    d2Level = nullptr;
    d2freqSlider = nullptr;

    d2time = nullptr;
    d2freq = nullptr;
    d2timeSlider = nullptr;
    d3LevelSlider = nullptr;
    d3Level = nullptr;
    d3freqSlider = nullptr;

    d3time = nullptr;
    d3freq = nullptr;
    d4LevelSlider = nullptr;
    d4Level = nullptr;
    d4freqSlider = nullptr;

    d4time = nullptr;
    d4freq = nullptr;
    d3timeSlider = nullptr;

    d5LevelSlider = nullptr;
    d5Level = nullptr;
    d5freqSlider = nullptr;

    d5time = nullptr;
    d5freq = nullptr;
    d6LevelSlider = nullptr;
    d6Level = nullptr;
    d6freqSlider = nullptr;

    d6time = nullptr;
    d6freq = nullptr;
    d5timeSlider = nullptr;
    d6timeSlider = nullptr;
    d7LevelSlider = nullptr;
    d7Level = nullptr;
    d7freqSlider = nullptr;

    d7time = nullptr;
    d7freq = nullptr;
    d8LevelSlider = nullptr;
    d8Level = nullptr;
    d8freqSlider = nullptr;

    d8time = nullptr;
    d8freq = nullptr;
    d7timeSlider = nullptr;

    label = nullptr;
    d4timeSlider = nullptr;
    d8timeSlider = nullptr;
    directLevelSlider = nullptr;
    directLevel = nullptr;
    moddepthSlider = nullptr;
    moddepth = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void C74GenAudioProcessorEditor::paint (Graphics& g)
{
g.fillAll (Colour (0xff446135));
}

void C74GenAudioProcessorEditor::resized()
{

    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

        //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    d1LevelSlider->setBounds (8, 40, 264, 16);
    d1Level->setBounds (272, 40, 64, 16);
    d1freqSlider->setBounds (8, 72, 264, 16);
    d1timeSlider->setBounds (8, 104, 264, 16);
    d1time->setBounds (272, 104, 64, 16);
    d1freq->setBounds (272, 72, 64, 16);
    d2LevelSlider->setBounds (8, 136, 264, 16);
    d2Level->setBounds (272, 136, 64, 16);
    d2freqSlider->setBounds (8, 168, 264, 16);

    d2time->setBounds (272, 200, 64, 16);
    d2freq->setBounds (272, 168, 64, 16);
    d2timeSlider->setBounds (8, 200, 264, 16);
    d3LevelSlider->setBounds (8, 232, 264, 16);
    d3Level->setBounds (272, 232, 64, 16);
    d3freqSlider->setBounds (8, 264, 264, 16);

    d3time->setBounds (272, 296, 64, 16);
    d3freq->setBounds (272, 264, 64, 16);
    d4LevelSlider->setBounds (8, 328, 264, 16);
    d4Level->setBounds (272, 328, 64, 16);
    d4freqSlider->setBounds (8, 360, 264, 16);

    d4time->setBounds (272, 392, 64, 16);
    d4freq->setBounds (272, 360, 64, 16);
    d3timeSlider->setBounds (8, 296, 264, 16);

    d5LevelSlider->setBounds (344, 40, 264, 16);
    d5Level->setBounds (608, 40, 64, 16);
    d5freqSlider->setBounds (344, 72, 264, 16);

    d5time->setBounds (608, 104, 64, 16);
    d5freq->setBounds (608, 72, 64, 16);
    d6LevelSlider->setBounds (344, 136, 264, 16);
    d6Level->setBounds (608, 136, 64, 16);
    d6freqSlider->setBounds (344, 168, 264, 16);

    d6time->setBounds (608, 200, 64, 16);
    d6freq->setBounds (608, 168, 64, 16);
    d5timeSlider->setBounds (344, 104, 264, 16);
    d6timeSlider->setBounds (344, 200, 264, 16);
    d7LevelSlider->setBounds (344, 232, 264, 16);
    d7Level->setBounds (608, 232, 64, 16);
    d7freqSlider->setBounds (344, 264, 264, 16);

    d7time->setBounds (608, 296, 64, 16);
    d7freq->setBounds (608, 264, 64, 16);
    d8LevelSlider->setBounds (344, 328, 264, 16);
    d8Level->setBounds (608, 328, 64, 16);
    d8freqSlider->setBounds (344, 360, 264, 16);

    d8time->setBounds (608, 392, 64, 16);
    d8freq->setBounds (608, 360, 64, 16);

    label->setBounds (16, 480, 512, 96);
    d4timeSlider->setBounds (8, 392, 264, 16);
    d8timeSlider->setBounds (344, 392, 264, 16);
    directLevelSlider->setBounds (8, 424, 264, 16);
    directLevel->setBounds (272, 416, 64, 40);
    moddepthSlider->setBounds (344, 424, 264, 16);
    moddepth->setBounds (608, 416, 80, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]

}

void C74GenAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == d1LevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(0,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d1freqSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(1,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d1timeSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(2,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d2LevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(3,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d2freqSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(4,sliderThatWasMoved->getValue());
    }

    else if (sliderThatWasMoved == d2timeSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(5,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d3LevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(6,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d3freqSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(7,sliderThatWasMoved->getValue());
    }
 
    else if (sliderThatWasMoved == d4LevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(9,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d4freqSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(10,sliderThatWasMoved->getValue());
    }

    else if (sliderThatWasMoved == d3timeSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(8,sliderThatWasMoved->getValue());
    }

    else if (sliderThatWasMoved == d5LevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(12,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d5freqSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(13,sliderThatWasMoved->getValue());
    }

    else if (sliderThatWasMoved == d6LevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(15,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d6freqSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(16,sliderThatWasMoved->getValue());
    }

    else if (sliderThatWasMoved == d5timeSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(14,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d6timeSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(17,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d7LevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(18,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d7freqSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(19,sliderThatWasMoved->getValue());
    }
 
    else if (sliderThatWasMoved == d8LevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(21,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d8freqSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(22,sliderThatWasMoved->getValue());
    }

    else if (sliderThatWasMoved == d7timeSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(20,sliderThatWasMoved->getValue());
    }

    else if (sliderThatWasMoved == d4timeSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(11,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == d8timeSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(23,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == directLevelSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(24,sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == moddepthSlider)
    {
       sliderThatWasMoved->getValue();
       processor.setParameter(25,sliderThatWasMoved->getValue());
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

