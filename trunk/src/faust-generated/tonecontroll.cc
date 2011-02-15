namespace tonecontroll {
// generated from file '../src/faust/tonecontroll.dsp'

double 	fConst0;
double 	fConst1;
double 	fConst2;
double 	fConst3;
double 	fConst4;
double 	fConst5;
double 	fConst6;
double 	fConst7;
double 	fConst8;
double 	fConst9;
double 	fConst10;
double 	fConst11;
double 	fConst12;
double 	fConst13;
double 	fConst14;
double 	fConst15;
double 	fConst16;
double 	fVec0[2];
double 	fConst17;
double 	fRec3[2];
double 	fRec2[3];
double 	fVec1[2];
double 	fConst18;
double 	fConst19;
double 	fRec1[2];
double 	fRec0[3];
double 	fConst20;
FAUSTFLOAT 	fslider0;
double 	fRec4[2];
double 	fRec6[2];
double 	fRec5[3];
FAUSTFLOAT 	fslider1;
double 	fRec7[2];
double 	fConst21;
double 	fConst22;
double 	fConst23;
double 	fRec10[2];
double 	fRec9[3];
double 	fConst24;
double 	fRec8[3];
FAUSTFLOAT 	fslider2;
double 	fRec11[2];
double 	fVec2[2];
double 	fRec15[2];
double 	fRec14[3];
double 	fVec3[2];
double 	fRec13[2];
double 	fRec12[3];
double 	fRec17[2];
double 	fRec16[3];
double 	fRec20[2];
double 	fRec19[3];
double 	fRec18[3];
int	fSamplingFreq;

void init(int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = tan((1884.9555921538758 / fSamplingFreq));
	fConst1 = (1.0 / faustpower<2>(fConst0));
	fConst2 = (2 * (1 - fConst1));
	fConst3 = (1.0 / fConst0);
	fConst4 = (1 + ((fConst3 - 1.0000000000000004) / fConst0));
	fConst5 = (1.0 / (1 + ((fConst3 + 1.0000000000000004) / fConst0)));
	fConst6 = (1 + fConst3);
	fConst7 = (0 - ((1 - fConst3) / fConst6));
	fConst8 = tan((7539.822368615503 / fSamplingFreq));
	fConst9 = (1.0 / faustpower<2>(fConst8));
	fConst10 = (2 * (1 - fConst9));
	fConst11 = (1.0 / fConst8);
	fConst12 = (1 + ((fConst11 - 1.0000000000000004) / fConst8));
	fConst13 = (1 + ((1.0000000000000004 + fConst11) / fConst8));
	fConst14 = (1.0 / fConst13);
	fConst15 = (1 + fConst11);
	fConst16 = (0 - ((1 - fConst11) / fConst15));
	for (int i=0; i<2; i++) fVec0[i] = 0;
	fConst17 = (1.0 / fConst15);
	for (int i=0; i<2; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	fConst18 = (0 - fConst3);
	fConst19 = (1.0 / (fConst6 * fConst13));
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<3; i++) fRec0[i] = 0;
	fConst20 = (2 * (0 - fConst1));
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<3; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec7[i] = 0;
	fConst21 = (1 + ((fConst3 - 1.0) / fConst0));
	fConst22 = (1.0 / (1 + ((1.0 + fConst3) / fConst0)));
	fConst23 = (0 - fConst11);
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<3; i++) fRec9[i] = 0;
	fConst24 = (2 * (0 - fConst9));
	for (int i=0; i<3; i++) fRec8[i] = 0;
	for (int i=0; i<2; i++) fRec11[i] = 0;
	for (int i=0; i<2; i++) fVec2[i] = 0;
	for (int i=0; i<2; i++) fRec15[i] = 0;
	for (int i=0; i<3; i++) fRec14[i] = 0;
	for (int i=0; i<2; i++) fVec3[i] = 0;
	for (int i=0; i<2; i++) fRec13[i] = 0;
	for (int i=0; i<3; i++) fRec12[i] = 0;
	for (int i=0; i<2; i++) fRec17[i] = 0;
	for (int i=0; i<3; i++) fRec16[i] = 0;
	for (int i=0; i<2; i++) fRec20[i] = 0;
	for (int i=0; i<3; i++) fRec19[i] = 0;
	for (int i=0; i<3; i++) fRec18[i] = 0;
}

void compute(int count, float *input0, float *input1, float *output0, float *output1)
{
	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * fslider0)));
	double 	fSlow1 = (0.0010000000000000009 * pow(10,(0.05 * fslider1)));
	double 	fSlow2 = (0.0010000000000000009 * pow(10,(0.05 * fslider2)));
	for (int i=0; i<count; i++) {
		double fTemp0 = (double)input0[i];
		fVec0[0] = fTemp0;
		fRec3[0] = ((fConst17 * (fVec0[0] + fVec0[1])) + (fConst16 * fRec3[1]));
		fRec2[0] = (fRec3[0] - (fConst14 * ((fConst12 * fRec2[2]) + (fConst10 * fRec2[1]))));
		double fTemp1 = (fRec2[2] + (fRec2[0] + (2 * fRec2[1])));
		fVec1[0] = fTemp1;
		fRec1[0] = ((fConst19 * ((fConst18 * fVec1[1]) + (fConst3 * fVec1[0]))) + (fConst7 * fRec1[1]));
		fRec0[0] = (fRec1[0] - (fConst5 * ((fConst4 * fRec0[2]) + (fConst2 * fRec0[1]))));
		fRec4[0] = (fSlow0 + (0.999 * fRec4[1]));
		fRec6[0] = ((fConst19 * (fVec1[0] + fVec1[1])) + (fConst7 * fRec6[1]));
		fRec5[0] = (fRec6[0] - (fConst5 * ((fConst4 * fRec5[2]) + (fConst2 * fRec5[1]))));
		fRec7[0] = (fSlow1 + (0.999 * fRec7[1]));
		double fTemp2 = (fConst2 * fRec8[1]);
		fRec10[0] = ((fConst17 * ((fConst23 * fVec0[1]) + (fConst11 * fVec0[0]))) + (fConst16 * fRec10[1]));
		fRec9[0] = (fRec10[0] - (fConst14 * ((fConst12 * fRec9[2]) + (fConst10 * fRec9[1]))));
		fRec8[0] = ((fConst14 * (((fConst9 * fRec9[0]) + (fConst24 * fRec9[1])) + (fConst9 * fRec9[2]))) - (fConst22 * ((fConst21 * fRec8[2]) + fTemp2)));
		fRec11[0] = (fSlow2 + (0.999 * fRec11[1]));
		output0[i] = (FAUSTFLOAT)((fRec11[0] * (fRec8[2] + (fConst22 * (fTemp2 + (fConst21 * fRec8[0]))))) + (fConst5 * ((fRec7[0] * (fRec5[2] + (fRec5[0] + (2 * fRec5[1])))) + (fRec4[0] * (((fConst1 * fRec0[0]) + (fConst20 * fRec0[1])) + (fConst1 * fRec0[2]))))));
		double fTemp3 = (double)input1[i];
		fVec2[0] = fTemp3;
		fRec15[0] = ((fConst17 * (fVec2[0] + fVec2[1])) + (fConst16 * fRec15[1]));
		fRec14[0] = (fRec15[0] - (fConst14 * ((fConst12 * fRec14[2]) + (fConst10 * fRec14[1]))));
		double fTemp4 = (fRec14[2] + (fRec14[0] + (2 * fRec14[1])));
		fVec3[0] = fTemp4;
		fRec13[0] = ((fConst19 * ((fConst18 * fVec3[1]) + (fConst3 * fVec3[0]))) + (fConst7 * fRec13[1]));
		fRec12[0] = (fRec13[0] - (fConst5 * ((fConst4 * fRec12[2]) + (fConst2 * fRec12[1]))));
		fRec17[0] = ((fConst19 * (fVec3[0] + fVec3[1])) + (fConst7 * fRec17[1]));
		fRec16[0] = (fRec17[0] - (fConst5 * ((fConst4 * fRec16[2]) + (fConst2 * fRec16[1]))));
		double fTemp5 = (fConst2 * fRec18[1]);
		fRec20[0] = ((fConst17 * ((fConst23 * fVec2[1]) + (fConst11 * fVec2[0]))) + (fConst16 * fRec20[1]));
		fRec19[0] = (fRec20[0] - (fConst14 * ((fConst12 * fRec19[2]) + (fConst10 * fRec19[1]))));
		fRec18[0] = ((fConst14 * (((fConst9 * fRec19[0]) + (fConst24 * fRec19[1])) + (fConst9 * fRec19[2]))) - (fConst22 * ((fConst21 * fRec18[2]) + fTemp5)));
		output1[i] = (FAUSTFLOAT)((fRec11[0] * (fRec18[2] + (fConst22 * (fTemp5 + (fConst21 * fRec18[0]))))) + (fConst5 * ((fRec7[0] * (fRec16[2] + (fRec16[0] + (2 * fRec16[1])))) + (fRec4[0] * (((fConst1 * fRec12[0]) + (fConst20 * fRec12[1])) + (fConst1 * fRec12[2]))))));
		// post processing
		fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
		fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
		fRec20[1] = fRec20[0];
		fRec16[2] = fRec16[1]; fRec16[1] = fRec16[0];
		fRec17[1] = fRec17[0];
		fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
		fRec13[1] = fRec13[0];
		fVec3[1] = fVec3[0];
		fRec14[2] = fRec14[1]; fRec14[1] = fRec14[0];
		fRec15[1] = fRec15[0];
		fVec2[1] = fVec2[0];
		fRec11[1] = fRec11[0];
		fRec8[2] = fRec8[1]; fRec8[1] = fRec8[0];
		fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
		fRec10[1] = fRec10[0];
		fRec7[1] = fRec7[0];
		fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
		fRec6[1] = fRec6[0];
		fRec4[1] = fRec4[0];
		fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
		fVec1[1] = fVec1[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fRec3[1] = fRec3[0];
		fVec0[1] = fVec0[0];
	}
}

static struct RegisterParams { RegisterParams(); } RegisterParams;
RegisterParams::RegisterParams()
{
	registerVar("tonemodul.Treble","","S","",&fslider2, 0.0, -5.0, 5.0, 0.01);
	registerVar("tonemodul.Bass","","S","",&fslider1, 0.0, -5.0, 5.0, 0.01);
	registerVar("tonemodul.Middle","","S","",&fslider0, 0.0, -5.0, 5.0, 0.01);
	registerInit("tonemodul", init);
}

} // end namespace tonecontroll
