/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CBDarkWorldEditorAudioProcessor::CBDarkWorldEditorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    addParameter (darkOn = new juce::AudioParameterBool ("DARKON", "Dark On", false));
    addParameter (worldOn = new juce::AudioParameterBool ("WORLDON", "World On", false));
    
    addParameter (decay = new juce::AudioParameterInt ("DECAY", "Decay", 1, 127, 63));
    addParameter (mix = new juce::AudioParameterInt ("MIX", "Mix", 1, 127, 63));
    addParameter (dwell = new juce::AudioParameterInt ("DWELL", "Dwell", 1, 127, 63));
    addParameter (modify = new juce::AudioParameterInt ("MODIFY", "Modify", 1, 127, 63));
    addParameter (tone = new juce::AudioParameterInt ("TONE", "Tone", 1, 127, 63));
    addParameter (preDelay = new juce::AudioParameterInt ("PREDELAY", "Pre-Delay", 1, 127, 63));
    
    addParameter (darkType = new juce::AudioParameterInt ("DARKTYPE", "Dark Reverb Type", 1, 3, 1));
    addParameter (effectOrder = new juce::AudioParameterInt ("EFFECTORDER", "Effect Order", 1, 3, 1));
    addParameter (worldType = new juce::AudioParameterInt ("WORLDTYPE", "World Reverb Type", 1, 3, 1));
}

CBDarkWorldEditorAudioProcessor::~CBDarkWorldEditorAudioProcessor()
{
}

//==============================================================================
const juce::String CBDarkWorldEditorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool CBDarkWorldEditorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CBDarkWorldEditorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CBDarkWorldEditorAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double CBDarkWorldEditorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CBDarkWorldEditorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CBDarkWorldEditorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CBDarkWorldEditorAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String CBDarkWorldEditorAudioProcessor::getProgramName (int index)
{
    return {};
}

void CBDarkWorldEditorAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void CBDarkWorldEditorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void CBDarkWorldEditorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool CBDarkWorldEditorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
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

void CBDarkWorldEditorAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    buffer.clear();
    midiMessages.clear();
    
    midiParams.setBypass (* darkOn, * worldOn);
    midiParams.setDecay (* decay);
    midiParams.setMix (* mix);
    midiParams.setDwell (* dwell);
    midiParams.setMod (* modify);
    midiParams.setTone (* tone);
    midiParams.setPreDelay (* preDelay);
    midiParams.setDarkType (* darkType);
    midiParams.setEffectOrder (* effectOrder);
    midiParams.setWorldType (* worldType);
    
    midiChange.processMIDI (midiMessages);
}

//==============================================================================
bool CBDarkWorldEditorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* CBDarkWorldEditorAudioProcessor::createEditor()
{
    return new CBDarkWorldEditorAudioProcessorEditor (*this);
}

//==============================================================================
void CBDarkWorldEditorAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    std::unique_ptr <juce::XmlElement> xml (new juce::XmlElement ("CBDarkWorldEditorParameters"));
        xml -> setAttribute ("DARKON", (double) * darkOn);
        xml -> setAttribute ("WORLDON", (double) * worldOn);
        xml -> setAttribute ("DECAY", (double) * decay);
        xml -> setAttribute ("MIX", (double) * mix);
        xml -> setAttribute ("DWELL", (double) * dwell);
        xml -> setAttribute ("MODIFY", (double) * modify);
        xml -> setAttribute ("TONE", (double) * tone);
        xml -> setAttribute ("PREDELAY", (double) * preDelay);
        xml -> setAttribute ("DARKON", (double) * darkOn);
        xml -> setAttribute ("EFFECTORDER", (double) * effectOrder);
        xml -> setAttribute ("WORLDON", (double) * worldOn);
    copyXmlToBinary (*xml, destData);
}

void CBDarkWorldEditorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr <juce::XmlElement> xml (getXmlFromBinary (data, sizeInBytes));
    if (xml != nullptr){
        if (xml -> hasTagName ("CBDarkWorldEditorParameters")){
            * darkOn = xml -> getBoolAttribute ("DARKON", false);
            * worldOn = xml -> getBoolAttribute ("WORLDON", false);
            * decay = xml -> getIntAttribute ("DECAY", 63);
            * mix = xml -> getIntAttribute ("MIX", 63);
            * dwell = xml -> getIntAttribute ("DWELL", 63);
            * modify = xml -> getIntAttribute ("MODIFY", 63);
            * tone = xml -> getIntAttribute ("TONE", 63);
            * preDelay = xml -> getIntAttribute ("PREDELAY", 63);
            * darkOn = xml -> getIntAttribute ("DARKON", 1);
            * effectOrder = xml -> getIntAttribute ("EFFECTORDER", 1);
            * worldOn = xml -> getIntAttribute ("WORLDON", 1);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CBDarkWorldEditorAudioProcessor();
}
