
# Retrieve the stereo input of the plugin.
st_input = Input([0,1])
# Parameters to change.
#dtime = SigTo(.5, 0.05, .5)
#feed = SigTo(.5, 0.05, .5)
# Simple process. Stereo delay -> reverb.
#st_delay = SmoothDelay(st_input, delay=dtime, feedback=feed)
#st_rev = WGVerb(st_delay, feedback=0.8, cutoff=4000, bal=0.25).out()
#a = Input(chnl=0)
freqs = [.214, .465, .657, .879, 1.23, 1.52, 1.75, 2.1]
# delay line center delays
cdelay = [.02, .015, .02, .015, .02, .015, .015, .02]
# delay line delay amplitudes
adelay = [.0009, .002, .003, .004, .0013, .0014, .0015, .0016]
# modulation depth
depth = Sig(0.33)
#<--
#--> Add the delay lines to the source sound
lfos = Sine(freqs, mul=adelay*depth, add=cdelay)
delays = Delay(st_input, lfos, feedback=.5, mul=.5).out()
#delays2 = Delay(a, lfos, feedback=.5, mul=.5).out(1)
