#include "C74_GENPLUGIN.h"

namespace C74_GENPLUGIN {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Delay m_delay_27;
	Delay m_delay_30;
	Delay m_delay_31;
	Delay m_delay_29;
	Delay m_delay_28;
	SineCycle __m_cycle_39;
	SineCycle __m_cycle_32;
	SineCycle __m_cycle_38;
	SineCycle __m_cycle_37;
	SineCycle __m_cycle_33;
	SineCycle __m_cycle_36;
	SineCycle __m_cycle_34;
	SineCycle __m_cycle_35;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_d7Level_7;
	t_sample m_d8time_13;
	t_sample m_d1freq_6;
	t_sample m_moddepth_8;
	t_sample m_d6Level_9;
	t_sample m_d2Level_5;
	t_sample m_d8freq_4;
	t_sample m_d8Level_3;
	t_sample samplerate;
	t_sample m_d5freq_10;
	t_sample m_d4Level_1;
	t_sample m_d2time_2;
	t_sample m_d4freq_12;
	t_sample m_d2freq_26;
	t_sample m_d1time_24;
	t_sample m_d1Level_16;
	t_sample m_d5Level_17;
	t_sample m_d3time_15;
	t_sample m_d6time_14;
	t_sample m_d5time_25;
	t_sample m_d3Level_18;
	t_sample m_d3freq_20;
	t_sample m_d7freq_23;
	t_sample m_d6freq_11;
	t_sample m_directLevel_22;
	t_sample m_d7time_21;
	t_sample m_d4time_19;
    // added feedback level paramaters
    t_sample m_d5FdBk_40;
    t_sample m_d6FdBk_41;
    t_sample m_d7FdBk_42;
    t_sample m_d8FdBk_43;
    // ((t_sample)0.5) (t_sample)0.4) (t_sample)0.5) (t_sample)0.38)
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
        m_d5FdBk_40 = ((t_sample)0.5);
        m_d6FdBk_41 = ((t_sample)0.4);
        m_d7FdBk_42 = ((t_sample)0.5);
        m_d8FdBk_43 = ((t_sample)0.38);
        
		m_d4Level_1 = ((t_sample)0.5);
		m_d2time_2 = ((int)34);
		m_d8Level_3 = ((t_sample)0.5);
		m_d8freq_4 = ((t_sample)0.54);
		m_d2Level_5 = ((t_sample)0.5);
		m_d1freq_6 = ((t_sample)0.43);
		m_d7Level_7 = ((t_sample)0.5);
		m_moddepth_8 = ((int)2);
		m_d6Level_9 = ((t_sample)0.5);
		m_d5freq_10 = ((t_sample)0.33);
		m_d6freq_11 = ((t_sample)0.31);
		m_d4freq_12 = ((t_sample)0.79);
		m_d8time_13 = ((int)450);
		m_d6time_14 = ((int)821);
		m_d3time_15 = ((int)50);
		m_d1Level_16 = ((t_sample)0.5);
		m_d5Level_17 = ((t_sample)0.5);
		m_d3Level_18 = ((t_sample)0.5);
		m_d4time_19 = ((int)40);
		m_d3freq_20 = ((t_sample)0.42);
		m_d7time_21 = ((int)741);
		m_directLevel_22 = ((t_sample)0.5);
		m_d7freq_23 = ((t_sample)0.47);
		m_d1time_24 = ((int)21);
		m_d5time_25 = ((int)612);
		m_d2freq_26 = ((t_sample)1.02);
		m_delay_27.reset("m_delay_27", ((int)96000));
		m_delay_28.reset("m_delay_28", samplerate);
		m_delay_29.reset("m_delay_29", samplerate);
		m_delay_30.reset("m_delay_30", samplerate);
		m_delay_31.reset("m_delay_31", samplerate);
		__m_cycle_32.reset(samplerate, 0);
		__m_cycle_33.reset(samplerate, 0);
		__m_cycle_34.reset(samplerate, 0);
		__m_cycle_35.reset(samplerate, 0);
		__m_cycle_36.reset(samplerate, 0);
		__m_cycle_37.reset(samplerate, 0);
		__m_cycle_38.reset(samplerate, 0);
		__m_cycle_39.reset(samplerate, 0);
        m_d5FdBk_40 =((t_sample)0.5);
        m_d6FdBk_41 =((t_sample)0.4);
        m_d7FdBk_42 =((t_sample)0.5);
        m_d8FdBk_43 =((t_sample)0.38);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample float_2071 = t_sample(m_d1freq_6);
		t_sample float_2064 = t_sample(m_d2freq_26);
		t_sample float_2070 = t_sample(m_d3freq_20);
		t_sample float_2069 = t_sample(m_d4freq_12);
		t_sample float_2068 = t_sample(m_d5freq_10);
		t_sample float_2066 = t_sample(m_d7freq_23);
		t_sample float_2067 = t_sample(m_d6freq_11);
		t_sample float_2065 = t_sample(m_d8freq_4);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample mul_2092 = (in1 * m_directLevel_22);
			t_sample mul_2093 = (in2 * m_directLevel_22);
			__m_cycle_32.freq(float_2071);
			t_sample cycle_2132 = __m_cycle_32(__sinedata);
			t_sample cycleindex_2133 = __m_cycle_32.phase();
			t_sample mul_2131 = (cycle_2132 * m_moddepth_8);
			t_sample add_2130 = (mul_2131 + m_d1time_24);
			t_sample mstosamps_2129 = (add_2130 * (samplerate * 0.001));
			__m_cycle_33.freq(float_2064);
			t_sample cycle_2127 = __m_cycle_33(__sinedata);
			t_sample cycleindex_2128 = __m_cycle_33.phase();
			t_sample mul_2126 = (cycle_2127 * m_moddepth_8);
			t_sample add_2125 = (mul_2126 + m_d2time_2);
			t_sample mstosamps_2124 = (add_2125 * (samplerate * 0.001));
			__m_cycle_34.freq(float_2070);
			t_sample cycle_2122 = __m_cycle_34(__sinedata);
			t_sample cycleindex_2123 = __m_cycle_34.phase();
			t_sample mul_2121 = (cycle_2122 * m_moddepth_8);
			t_sample add_2120 = (mul_2121 + m_d3time_15);
			t_sample mstosamps_2119 = (add_2120 * (samplerate * 0.001));
			__m_cycle_35.freq(float_2069);
			t_sample cycle_2117 = __m_cycle_35(__sinedata);
			t_sample cycleindex_2118 = __m_cycle_35.phase();
			t_sample mul_2116 = (cycle_2117 * m_moddepth_8);
			t_sample add_2115 = (mul_2116 + m_d4time_19);
			t_sample mstosamps_2114 = (add_2115 * (samplerate * 0.001));
			t_sample tap_2135 = m_delay_27.read_linear(mstosamps_2129);
			t_sample tap_2136 = m_delay_27.read_linear(mstosamps_2124);
			t_sample tap_2137 = m_delay_27.read_linear(mstosamps_2119);
			t_sample tap_2138 = m_delay_27.read_linear(mstosamps_2114);
			t_sample mul_2091 = (tap_2135 * m_d1Level_16);
			t_sample mul_2089 = (tap_2137 * m_d3Level_18);
			t_sample mul_2090 = (tap_2136 * m_d2Level_5);
			t_sample mul_2088 = (tap_2138 * m_d4Level_1);
			__m_cycle_36.freq(float_2068);
			t_sample cycle_2112 = __m_cycle_36(__sinedata);
			t_sample cycleindex_2113 = __m_cycle_36.phase();
			t_sample mul_2094 = (cycle_2112 * m_moddepth_8);
			t_sample add_2111 = (mul_2094 + m_d5time_25);
			t_sample mstosamps_2110 = (add_2111 * (samplerate * 0.001));
			t_sample tap_2083 = m_delay_28.read_linear(mstosamps_2110);
			t_sample mul_2087 = (tap_2083 * m_d5Level_17);
			t_sample mul_2074 = (mul_2087 * m_d5FdBk_40);
            // (t_sample)0.5) (t_sample)0.4) (t_sample)0.5) (t_sample)0.38)
			__m_cycle_37.freq(float_2066);
			t_sample cycle_2103 = __m_cycle_37(__sinedata);
			t_sample cycleindex_2104 = __m_cycle_37.phase();
			t_sample mul_2102 = (cycle_2103 * m_moddepth_8);
			t_sample add_2101 = (mul_2102 + m_d7time_21);
			t_sample mstosamps_2100 = (add_2101 * (samplerate * 0.001));
			t_sample tap_2079 = m_delay_29.read_linear(mstosamps_2100);
			t_sample mul_2084 = (tap_2079 * m_d7Level_7);
			t_sample out1 = ((((mul_2084 + mul_2087) + mul_2089) + mul_2091) + mul_2092);
			t_sample mul_2073 = (mul_2084 * m_d7FdBk_42);

			__m_cycle_38.freq(float_2067);
			t_sample cycle_2108 = __m_cycle_38(__sinedata);
			t_sample cycleindex_2109 = __m_cycle_38.phase();
			t_sample mul_2107 = (cycle_2108 * m_moddepth_8);
			t_sample add_2106 = (mul_2107 + m_d6time_14);
			t_sample mstosamps_2105 = (add_2106 * (samplerate * 0.001));
			t_sample tap_2081 = m_delay_30.read_linear(mstosamps_2105);
			t_sample mul_2086 = (tap_2081 * m_d6Level_9);
			t_sample mul_2072 = (mul_2086 * m_d6FdBk_41);

			__m_cycle_39.freq(float_2065);
			t_sample cycle_2098 = __m_cycle_39(__sinedata);
			t_sample cycleindex_2099 = __m_cycle_39.phase();
			t_sample mul_2097 = (cycle_2098 * m_moddepth_8);
			t_sample add_2096 = (mul_2097 + m_d8time_13);
			t_sample mstosamps_2095 = (add_2096 * (samplerate * 0.001));
			t_sample tap_2077 = m_delay_31.read_linear(mstosamps_2095);
			t_sample mul_2085 = (tap_2077 * m_d8Level_3);
			t_sample out2 = ((((mul_2085 + mul_2086) + mul_2088) + mul_2090) + mul_2093);
			t_sample mul_2075 = (mul_2085 * m_d8FdBk_43);
			m_delay_27.write((in2 + in1));
			m_delay_31.write(((mul_2075 + in2) + in1));
			m_delay_30.write(((mul_2072 + in2) + in1));
			m_delay_29.write(((mul_2073 + in2) + in1));
			m_delay_28.write(((mul_2074 + in2) + in1));
			m_delay_27.step();
			m_delay_28.step();
			m_delay_29.step();
			m_delay_30.step();
			m_delay_31.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_d4Level(t_param _value) {
		m_d4Level_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d2time(t_param _value) {
		m_d2time_2 = (_value < 1 ? 1 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_d8Level(t_param _value) {
		m_d8Level_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d8freq(t_param _value) {
		m_d8freq_4 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
	inline void set_d2Level(t_param _value) {
		m_d2Level_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d1freq(t_param _value) {
		m_d1freq_6 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
	inline void set_d7Level(t_param _value) {
		m_d7Level_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_moddepth(t_param _value) {
		m_moddepth_8 = (_value < 1 ? 1 : (_value > 5 ? 5 : _value));
	};
	inline void set_d6Level(t_param _value) {
		m_d6Level_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d5freq(t_param _value) {
		m_d5freq_10 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
	inline void set_d6freq(t_param _value) {
		m_d6freq_11 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
	inline void set_d4freq(t_param _value) {
		m_d4freq_12 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
	inline void set_d8time(t_param _value) {
		m_d8time_13 = (_value < 1 ? 1 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_d6time(t_param _value) {
		m_d6time_14 = (_value < 1 ? 1 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_d3time(t_param _value) {
		m_d3time_15 = (_value < 1 ? 1 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_d1Level(t_param _value) {
		m_d1Level_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d5Level(t_param _value) {
		m_d5Level_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d3Level(t_param _value) {
		m_d3Level_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d4time(t_param _value) {
		m_d4time_19 = (_value < 1 ? 1 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_d3freq(t_param _value) {
		m_d3freq_20 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
	inline void set_d7time(t_param _value) {
		m_d7time_21 = (_value < 1 ? 1 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_directLevel(t_param _value) {
		m_directLevel_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_d7freq(t_param _value) {
		m_d7freq_23 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
	inline void set_d1time(t_param _value) {
		m_d1time_24 = (_value < 1 ? 1 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_d5time(t_param _value) {
		m_d5time_25 = (_value < 1 ? 1 : (_value > 1000 ? 1000 : _value));
	};
	inline void set_d2freq(t_param _value) {
		m_d2freq_26 = (_value < 0 ? 0 : (_value > 5 ? 5 : _value));
	};
    inline void set_d5FdBk(t_param _value) {
        m_d5FdBk_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
    };
    inline void set_d6FdBk(t_param _value) {
        m_d6FdBk_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
    };
    inline void set_d7FdBk(t_param _value) {
        m_d7FdBk_42 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
    };
    inline void set_d8FdBk(t_param _value) {
        m_d8FdBk_43 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
    };
    
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 30; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_d1Level(value); break;
		case 1: self->set_d1freq(value); break;
		case 2: self->set_d1time(value); break;
		case 3: self->set_d2Level(value); break;
		case 4: self->set_d2freq(value); break;
		case 5: self->set_d2time(value); break;
		case 6: self->set_d3Level(value); break;
		case 7: self->set_d3freq(value); break;
		case 8: self->set_d3time(value); break;
		case 9: self->set_d4Level(value); break;
		case 10: self->set_d4freq(value); break;
		case 11: self->set_d4time(value); break;
		case 12: self->set_d5Level(value); break;
		case 13: self->set_d5freq(value); break;
		case 14: self->set_d5time(value); break;
		case 15: self->set_d6Level(value); break;
		case 16: self->set_d6freq(value); break;
		case 17: self->set_d6time(value); break;
		case 18: self->set_d7Level(value); break;
		case 19: self->set_d7freq(value); break;
		case 20: self->set_d7time(value); break;
		case 21: self->set_d8Level(value); break;
		case 22: self->set_d8freq(value); break;
		case 23: self->set_d8time(value); break;
		case 24: self->set_directLevel(value); break;
		case 25: self->set_moddepth(value); break;
        case 26: self->set_d5FdBk(value); break;
        case 27: self->set_d6FdBk(value); break;
        case 28: self->set_d7FdBk(value); break;
        case 29: self->set_d8FdBk(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_d1Level_16; break;
		case 1: *value = self->m_d1freq_6; break;
		case 2: *value = self->m_d1time_24; break;
		case 3: *value = self->m_d2Level_5; break;
		case 4: *value = self->m_d2freq_26; break;
		case 5: *value = self->m_d2time_2; break;
		case 6: *value = self->m_d3Level_18; break;
		case 7: *value = self->m_d3freq_20; break;
		case 8: *value = self->m_d3time_15; break;
		case 9: *value = self->m_d4Level_1; break;
		case 10: *value = self->m_d4freq_12; break;
		case 11: *value = self->m_d4time_19; break;
		case 12: *value = self->m_d5Level_17; break;
		case 13: *value = self->m_d5freq_10; break;
		case 14: *value = self->m_d5time_25; break;
		case 15: *value = self->m_d6Level_9; break;
		case 16: *value = self->m_d6freq_11; break;
		case 17: *value = self->m_d6time_14; break;
		case 18: *value = self->m_d7Level_7; break;
		case 19: *value = self->m_d7freq_23; break;
		case 20: *value = self->m_d7time_21; break;
		case 21: *value = self->m_d8Level_3; break;
		case 22: *value = self->m_d8freq_4; break;
		case 23: *value = self->m_d8time_13; break;
		case 24: *value = self->m_directLevel_22; break;
		case 25: *value = self->m_moddepth_8; break;
        case 26: *value = self->m_d5FdBk_40; break;
        case 27: *value = self->m_d6FdBk_41; break;
        case 28: *value = self->m_d7FdBk_42; break;
        case 29: *value = self->m_d8FdBk_43; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(30 * sizeof(ParamInfo));
	self->__commonstate.numparams = 30;
	// initialize parameter 0 ("m_d1Level_16")
	pi = self->__commonstate.params + 0;
	pi->name = "d1Level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d1Level_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_d1freq_6")
	pi = self->__commonstate.params + 1;
	pi->name = "d1freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d1freq_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_d1time_24")
	pi = self->__commonstate.params + 2;
	pi->name = "d1time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d1time_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_d2Level_5")
	pi = self->__commonstate.params + 3;
	pi->name = "d2Level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d2Level_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_d2freq_26")
	pi = self->__commonstate.params + 4;
	pi->name = "d2freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d2freq_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_d2time_2")
	pi = self->__commonstate.params + 5;
	pi->name = "d2time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d2time_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_d3Level_18")
	pi = self->__commonstate.params + 6;
	pi->name = "d3Level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d3Level_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_d3freq_20")
	pi = self->__commonstate.params + 7;
	pi->name = "d3freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d3freq_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_d3time_15")
	pi = self->__commonstate.params + 8;
	pi->name = "d3time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d3time_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_d4Level_1")
	pi = self->__commonstate.params + 9;
	pi->name = "d4Level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d4Level_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_d4freq_12")
	pi = self->__commonstate.params + 10;
	pi->name = "d4freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d4freq_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_d4time_19")
	pi = self->__commonstate.params + 11;
	pi->name = "d4time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d4time_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_d5Level_17")
	pi = self->__commonstate.params + 12;
	pi->name = "d5Level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d5Level_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_d5freq_10")
	pi = self->__commonstate.params + 13;
	pi->name = "d5freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d5freq_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_d5time_25")
	pi = self->__commonstate.params + 14;
	pi->name = "d5time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d5time_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_d6Level_9")
	pi = self->__commonstate.params + 15;
	pi->name = "d6Level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d6Level_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_d6freq_11")
	pi = self->__commonstate.params + 16;
	pi->name = "d6freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d6freq_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_d6time_14")
	pi = self->__commonstate.params + 17;
	pi->name = "d6time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d6time_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_d7Level_7")
	pi = self->__commonstate.params + 18;
	pi->name = "d7Level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d7Level_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_d7freq_23")
	pi = self->__commonstate.params + 19;
	pi->name = "d7freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d7freq_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_d7time_21")
	pi = self->__commonstate.params + 20;
	pi->name = "d7time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d7time_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_d8Level_3")
	pi = self->__commonstate.params + 21;
	pi->name = "d8Level";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d8Level_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_d8freq_4")
	pi = self->__commonstate.params + 22;
	pi->name = "d8freq";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d8freq_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_d8time_13")
	pi = self->__commonstate.params + 23;
	pi->name = "d8time";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_d8time_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 1000;
	pi->exp = 0;
	pi->units = "";		// no units defined
    // initialize parameter 26 ("")
    pi = self->__commonstate.params + 26;
    pi->name = "d5FdBk";
    pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
    pi->defaultvalue = self->m_d5FdBk_40;
    pi->defaultref = 0;
    pi->hasinputminmax = false;
    pi->inputmin = 0;
    pi->inputmax = 1;
    pi->hasminmax = true;
    pi->outputmin = 0;
    pi->outputmax = 1;
    pi->exp = 0;
    pi->units = "";		// no units defined
    // initialize parameter 27 ("")
    pi = self->__commonstate.params + 27;
    pi->name = "d6FdBk";
    pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
    pi->defaultvalue = self->m_d6FdBk_41;
    pi->defaultref = 0;
    pi->hasinputminmax = false;
    pi->inputmin = 0;
    pi->inputmax = 1;
    pi->hasminmax = true;
    pi->outputmin = 0;
    pi->outputmax = 1;
    pi->exp = 0;
    pi->units = "";		// no units defined
        // initialize parameter 28 ("")
    pi = self->__commonstate.params + 28;
    pi->name = "d7FdBk";
    pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
    pi->defaultvalue = self->m_d7FdBk_42;
    pi->defaultref = 0;
    pi->hasinputminmax = false;
    pi->inputmin = 0;
    pi->inputmax = 1;
    pi->hasminmax = true;
    pi->outputmin = 0;
    pi->outputmax = 1;
    pi->exp = 0;
    pi->units = "";		// no units defined
    // initialize parameter 29 ("")
    pi = self->__commonstate.params + 29;
    pi->name = "d8FdBk";
    pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
    pi->defaultvalue = self->m_d8FdBk_43;
    pi->defaultref = 0;
    pi->hasinputminmax = false;
    pi->inputmin = 0;
    pi->inputmax = 1;
    pi->hasminmax = true;
    pi->outputmin = 0;
    pi->outputmax = 1;
    pi->exp = 0;
    pi->units = "";		// no units defined
    
	// initialize parameter 24 ("m_directLevel_22")
	pi = self->__commonstate.params + 24;
	pi->name = "directLevel";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_directLevel_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 25 ("m_moddepth_8")
	pi = self->__commonstate.params + 25;
	pi->name = "moddepth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_moddepth_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 5;
	pi->exp = 0;
	pi->units = "";		// no units defined
    
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // C74_GENPLUGIN::
