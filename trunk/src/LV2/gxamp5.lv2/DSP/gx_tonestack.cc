/*
 * Copyright (C) 2012 Hermann Meyer, Andreas Degert, Pete Shorthose
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * --------------------------------------------------------------------------
 */



inline void TonestackMono::clear_state_f()
{
  for (int32_t i=0; i<4; i++) fRec0[i] = 0;
}

inline void TonestackMono::init(uint32_t samplingFreq)
{

  fSamplingFreq = samplingFreq;
  fConst0 = (2 * double(min(192000, max(1, fSamplingFreq))));
  fConst1 = faustpower<2>(fConst0);
  fConst2 = (3 * fConst0);
  clear_state_f();
}

void TonestackMono::connect(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case MID:
      fslider0_ = (float*)data;
      break;
    case BASS:
      fslider1_ = (float*)data;
      break;
    case TREBLE:
      fslider2_ = (float*)data;
      break;
    default:
      break;
    }
}

inline void TonestackMono::run(uint32_t n_samples, float *output)   //sovtek
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;
  double 	fSlow0 = fslider0;
  double 	fSlow1 = (4.9434000000000004e-08 * fSlow0);
  double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
  double 	fSlow3 = (7.748796000000001e-07 + ((2.8889960000000004e-05 * fSlow2) + (fSlow0 * (((4.943400000000001e-06 * fSlow2) - 1.2634599999999999e-07) - fSlow1))));
  double 	fSlow4 = ((1.2443156000000004e-09 * fSlow2) - (1.2443156000000002e-11 * fSlow0));
  double 	fSlow5 = (5.345780000000001e-09 * fSlow2);
  double 	fSlow6 = (5.345780000000001e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 4.101464400000001e-11))));
  double 	fSlow7 = (fConst0 * fSlow6);
  double 	fSlow8 = (0.00022 * fSlow0);
  double 	fSlow9 = (0.022470000000000004 * fSlow2);
  double 	fSlow10 = (fConst0 * (0.0025277 + (fSlow9 + fSlow8)));
  double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
  double 	fSlow12 = (fConst2 * fSlow6);
  double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
  double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
  double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
  double 	fSlow16 = fslider2;
  double 	fSlow17 = ((fSlow0 * (1.2443156000000002e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (5.345780000000001e-11 - (5.345780000000001e-11 * fSlow0)))));
  double 	fSlow18 = (fConst2 * fSlow17);
  double 	fSlow19 = (6.141960000000001e-08 + (((4.859800000000001e-07 * fSlow16) + (fSlow0 * (1.0113400000000001e-07 - fSlow1))) + (fSlow2 * (6.141960000000001e-06 + (4.943400000000001e-06 * fSlow0)))));
  double 	fSlow20 = (0.00022470000000000001 + (fSlow9 + (fSlow8 + (0.00023500000000000002 * fSlow16))));
  double 	fSlow21 = (fConst0 * fSlow20);
  double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
  double 	fSlow23 = (fConst0 * fSlow17);
  double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
  double 	fSlow25 = (fConst0 * (0 - fSlow20));
  double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
  double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
  for (uint32_t i=0; i<n_samples; i++)
    {
      fRec0[0] = ((double)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
      output[i] = (float)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
      // post processing
      for (int32_t i=3; i>0; i--) fRec0[i] = fRec0[i-1];
    }
}


inline void TonestackMono::run_soldano(uint32_t n_samples, float *output)   //soldano
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;
  double 	fSlow0 = fslider0;
  double 	fSlow1 = (2.5587500000000006e-07 * fSlow0);
  double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
  double 	fSlow3 = (7.717400000000001e-07 + ((2.2033600000000005e-05 * fSlow2) + (fSlow0 * (((1.0235000000000001e-05 * fSlow2) - 1.5537499999999997e-07) - fSlow1))));
  double 	fSlow4 = ((1.3959000000000001e-09 * fSlow2) - (3.48975e-11 * fSlow0));
  double 	fSlow5 = (2.2090000000000005e-09 * fSlow2);
  double 	fSlow6 = (5.522500000000001e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 2.0327500000000007e-11))));
  double 	fSlow7 = (fConst0 * fSlow6);
  double 	fSlow8 = (0.0005 * fSlow0);
  double 	fSlow9 = (0.020470000000000002 * fSlow2);
  double 	fSlow10 = (fConst0 * (0.0025092499999999998 + (fSlow9 + fSlow8)));
  double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
  double 	fSlow12 = (fConst2 * fSlow6);
  double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
  double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
  double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
  double 	fSlow16 = fslider2;
  double 	fSlow17 = ((fSlow0 * (3.48975e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (5.522500000000001e-11 - (5.522500000000001e-11 * fSlow0)))));
  double 	fSlow18 = (fConst2 * fSlow17);
  double 	fSlow19 = (8.084000000000001e-08 + (((2.2090000000000003e-07 * fSlow16) + (fSlow0 * (3.146250000000001e-07 - fSlow1))) + (fSlow2 * (3.2336000000000007e-06 + (1.0235000000000001e-05 * fSlow0)))));
  double 	fSlow20 = (0.00051175 + (fSlow9 + (fSlow8 + (0.00011750000000000001 * fSlow16))));
  double 	fSlow21 = (fConst0 * fSlow20);
  double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
  double 	fSlow23 = (fConst0 * fSlow17);
  double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
  double 	fSlow25 = (fConst0 * (0 - fSlow20));
  double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
  double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
  for (uint32_t i=0; i<n_samples; i++)
    {
      fRec0[0] = ((double)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
      output[i] = (float)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
      // post processing
      for (int32_t i=3; i>0; i--) fRec0[i] = fRec0[i-1];
    }
}

inline void TonestackMono::run_bassman(uint32_t n_samples, float *output)   //bassman
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;
  double 	fSlow0 = fslider0;
  double 	fSlow1 = (2.5312500000000006e-07 * fSlow0);
  double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
  double 	fSlow3 = (7.4525e-07 + ((2.4210000000000004e-05 * fSlow2) + (fSlow0 * (((1.0125e-05 * fSlow2) - 2.75625e-07) - fSlow1))));
  double 	fSlow4 = ((7.650000000000002e-10 * fSlow2) - (1.9125000000000002e-11 * fSlow0));
  double 	fSlow5 = (1.4000000000000001e-09 * fSlow2);
  double 	fSlow6 = (3.500000000000001e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 1.5875000000000007e-11))));
  double 	fSlow7 = (fConst0 * fSlow6);
  double 	fSlow8 = (0.0005 * fSlow0);
  double 	fSlow9 = (0.02025 * fSlow2);
  double 	fSlow10 = (fConst0 * (0.0028087500000000005 + (fSlow9 + fSlow8)));
  double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
  double 	fSlow12 = (fConst2 * fSlow6);
  double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
  double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
  double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
  double 	fSlow16 = fslider2;
  double 	fSlow17 = ((fSlow0 * (1.9125000000000002e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (3.500000000000001e-11 - (3.500000000000001e-11 * fSlow0)))));
  double 	fSlow18 = (fConst2 * fSlow17);
  double 	fSlow19 = (4.525e-08 + (((1.4e-07 * fSlow16) + (fSlow0 * (2.8437500000000003e-07 - fSlow1))) + (fSlow2 * (1.8100000000000002e-06 + (1.0125e-05 * fSlow0)))));
  double 	fSlow20 = (0.00050625 + (fSlow9 + (fSlow8 + (6.25e-05 * fSlow16))));
  double 	fSlow21 = (fConst0 * fSlow20);
  double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
  double 	fSlow23 = (fConst0 * fSlow17);
  double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
  double 	fSlow25 = (fConst0 * (0 - fSlow20));
  double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
  double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
  for (uint32_t i=0; i<n_samples; i++)
    {
      fRec0[0] = ((double)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
      output[i] = (float)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
      // post processing
      for (int32_t i=3; i>0; i--) fRec0[i] = fRec0[i-1];
    }

}


inline void TonestackMono::run_ampeg(uint32_t n_samples, float *output)   //ampeg
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;
  double 	fSlow0 = fslider0;
  double 	fSlow1 = (3.0896250000000005e-07 * fSlow0);
  double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
  double 	fSlow3 = (6.338090000000001e-07 + ((1.8734760000000003e-05 * fSlow2) + (fSlow0 * (((1.2358500000000002e-05 * fSlow2) - 1.361249999999999e-08) - fSlow1))));
  double 	fSlow4 = ((1.6037340000000005e-09 * fSlow2) - (4.0093350000000015e-11 * fSlow0));
  double 	fSlow5 = (1.8198400000000004e-09 * fSlow2);
  double 	fSlow6 = (4.5496000000000015e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 5.40265e-12))));
  double 	fSlow7 = (fConst0 * fSlow6);
  double 	fSlow8 = (0.00055 * fSlow0);
  double 	fSlow9 = (0.022470000000000004 * fSlow2);
  double 	fSlow10 = (fConst0 * (0.00208725 + (fSlow9 + fSlow8)));
  double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
  double 	fSlow12 = (fConst2 * fSlow6);
  double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
  double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
  double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
  double 	fSlow16 = fslider2;
  double 	fSlow17 = ((fSlow0 * (4.0093350000000015e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (4.5496000000000015e-11 - (4.5496000000000015e-11 * fSlow0)))));
  double 	fSlow18 = (fConst2 * fSlow17);
  double 	fSlow19 = (8.1169e-08 + (((1.6544000000000003e-07 * fSlow16) + (fSlow0 * (3.735875000000001e-07 - fSlow1))) + (fSlow2 * (3.24676e-06 + (1.2358500000000002e-05 * fSlow0)))));
  double 	fSlow20 = (0.0005617500000000001 + (fSlow9 + (fSlow8 + (0.00011750000000000001 * fSlow16))));
  double 	fSlow21 = (fConst0 * fSlow20);
  double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
  double 	fSlow23 = (fConst0 * fSlow17);
  double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
  double 	fSlow25 = (fConst0 * (0 - fSlow20));
  double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
  double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
  for (uint32_t i=0; i<n_samples; i++)
    {
      fRec0[0] = ((double)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
      output[i] = (float)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
      // post processing
      for (int32_t i=3; i>0; i--) fRec0[i] = fRec0[i-1];
    }
}

inline void TonestackMono::run_ac30(uint32_t n_samples, float *output)   //AC30
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;

	double 	fSlow0 = fslider0;
	double 	fSlow1 = (4.851e-08 * fSlow0);
	double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
	double 	fSlow3 = (7.172000000000001e-07 + ((4.972000000000001e-05 * fSlow2) + (fSlow0 * (((4.8510000000000015e-06 * fSlow2) - 4.2449000000000006e-07) - fSlow1))));
	double 	fSlow4 = ((2.6620000000000007e-10 * fSlow2) - (2.662e-12 * fSlow0));
	double 	fSlow5 = (2.4200000000000003e-09 * fSlow2);
	double 	fSlow6 = (2.4200000000000004e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 2.1538000000000003e-11))));
	double 	fSlow7 = (fConst0 * fSlow6);
	double 	fSlow8 = (0.00022 * fSlow0);
	double 	fSlow9 = (0.022050000000000004 * fSlow2);
	double 	fSlow10 = (fConst0 * (0.0046705 + (fSlow9 + fSlow8)));
	double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
	double 	fSlow12 = (fConst2 * fSlow6);
	double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
	double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
	double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
	double 	fSlow16 = fslider2;
	double 	fSlow17 = ((fSlow0 * (2.662e-12 + fSlow4)) + (fSlow16 * (fSlow5 + (2.4200000000000004e-11 - (2.4200000000000004e-11 * fSlow0)))));
	double 	fSlow18 = (fConst2 * fSlow17);
	double 	fSlow19 = (1.32e-08 + (((2.2000000000000004e-07 * fSlow16) + (fSlow0 * (5.951000000000001e-08 - fSlow1))) + (fSlow2 * (1.32e-06 + (4.8510000000000015e-06 * fSlow0)))));
	double 	fSlow20 = (0.00022050000000000002 + (fSlow9 + (fSlow8 + (5e-05 * fSlow16))));
	double 	fSlow21 = (fConst0 * fSlow20);
	double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
	double 	fSlow23 = (fConst0 * fSlow17);
	double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
	double 	fSlow25 = (fConst0 * (0 - fSlow20));
	double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
	double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
	for (uint32_t i=0; i < n_samples; i++) {
		fRec0[0] = ((double)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
		output[i] = (FAUSTFLOAT)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
		// post processing
		for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
	}

}

inline void TonestackMono::run_twin(uint32_t n_samples, float *output)   //Twin
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;
	double 	fSlow0 = fslider0;
	double 	fSlow1 = (4.7056400000000006e-07 * fSlow0);
	double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
	double 	fSlow3 = (5.188640000000001e-06 + ((0.00011869100000000002 * fSlow2) + (fSlow0 * (((1.1764100000000001e-05 * fSlow2) - 4.215336e-06) - fSlow1))));
	double 	fSlow4 = ((4.935e-10 * fSlow2) - (1.974e-11 * fSlow0));
	double 	fSlow5 = (3.525e-09 * fSlow2);
	double 	fSlow6 = (1.41e-10 + (fSlow5 + (fSlow0 * (fSlow4 - 1.2126e-10))));
	double 	fSlow7 = (fConst0 * fSlow6);
	double 	fSlow8 = (0.00047000000000000004 * fSlow0);
	double 	fSlow9 = (0.02503 * fSlow2);
	double 	fSlow10 = (fConst0 * (0.0157312 + (fSlow9 + fSlow8)));
	double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
	double 	fSlow12 = (fConst2 * fSlow6);
	double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
	double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
	double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
	double 	fSlow16 = fslider2;
	double 	fSlow17 = ((fSlow0 * (1.974e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (1.41e-10 - (1.41e-10 * fSlow0)))));
	double 	fSlow18 = (fConst2 * fSlow17);
	double 	fSlow19 = (4.764000000000001e-08 + (((4.410000000000001e-07 * fSlow16) + (fSlow0 * (4.846640000000001e-07 - fSlow1))) + (fSlow2 * (1.1910000000000001e-06 + (1.1764100000000001e-05 * fSlow0)))));
	double 	fSlow20 = (0.0010012 + (fSlow9 + (fSlow8 + (3e-05 * fSlow16))));
	double 	fSlow21 = (fConst0 * fSlow20);
	double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
	double 	fSlow23 = (fConst0 * fSlow17);
	double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
	double 	fSlow25 = (fConst0 * (0 - fSlow20));
	double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
	double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
	for (uint32_t i=0; i<n_samples; i++) {
		fRec0[0] = ((double)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
		output[i] = (FAUSTFLOAT)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
		// post processing
		for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
	}
}
inline void TonestackMono::run_champ(uint32_t n_samples, float *output)   //Champ ??
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;

	double 	fSlow0 = fslider0;
	double 	fSlow1 = (4.7117500000000004e-07 * fSlow0);
	double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
	double 	fSlow3 = (5.718000000000001e-06 + ((0.00011998125000000002 * fSlow2) + (fSlow0 * (((1.1779375000000001e-05 * fSlow2) - 4.199450000000001e-06) - fSlow1))));
	double 	fSlow4 = ((1.0281250000000001e-09 * fSlow2) - (4.1125e-11 * fSlow0));
	double 	fSlow5 = (7.343750000000001e-09 * fSlow2);
	double 	fSlow6 = (2.9375e-10 + (fSlow5 + (fSlow0 * (fSlow4 - 2.52625e-10))));
	double 	fSlow7 = (fConst0 * fSlow6);
	double 	fSlow8 = (0.00047000000000000004 * fSlow0);
	double 	fSlow9 = (0.0250625 * fSlow2);
	double 	fSlow10 = (fConst0 * (0.015765 + (fSlow9 + fSlow8)));
	double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
	double 	fSlow12 = (fConst2 * fSlow6);
	double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
	double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
	double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
	double 	fSlow16 = fslider2;
	double 	fSlow17 = ((fSlow0 * (4.1125e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (2.9375e-10 - (2.9375e-10 * fSlow0)))));
	double 	fSlow18 = (fConst2 * fSlow17);
	double 	fSlow19 = (9.925e-08 + (((9.187500000000001e-07 * fSlow16) + (fSlow0 * (5.0055e-07 - fSlow1))) + (fSlow2 * (2.48125e-06 + (1.1779375000000001e-05 * fSlow0)))));
	double 	fSlow20 = (0.0010025 + (fSlow9 + (fSlow8 + (6.25e-05 * fSlow16))));
	double 	fSlow21 = (fConst0 * fSlow20);
	double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
	double 	fSlow23 = (fConst0 * fSlow17);
	double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
	double 	fSlow25 = (fConst0 * (0 - fSlow20));
	double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
	double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
	for (uint32_t i=0; i<n_samples; i++) {
		fRec0[0] = ((double)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
		output[i] = (FAUSTFLOAT)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
		// post processing
		for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
	}
}

inline void TonestackMono::run_princeton(uint32_t n_samples, float *output)   //Princeton
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;

	double 	fSlow0 = fslider0;
	double 	fSlow1 = (1.0855872000000003e-07 * fSlow0);
	double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
	double 	fSlow3 = (3.222390000000001e-06 + ((0.00011998125000000002 * fSlow2) + (fSlow0 * (((5.6541000000000015e-06 * fSlow2) - 2.1333412800000006e-06) - fSlow1))));
	double 	fSlow4 = ((4.935e-10 * fSlow2) - (9.4752e-12 * fSlow0));
	double 	fSlow5 = (7.343750000000001e-09 * fSlow2);
	double 	fSlow6 = (1.41e-10 + (fSlow5 + (fSlow0 * (fSlow4 - 1.315248e-10))));
	double 	fSlow7 = (fConst0 * fSlow6);
	double 	fSlow8 = (0.0002256 * fSlow0);
	double 	fSlow9 = (0.0250625 * fSlow2);
	double 	fSlow10 = (fConst0 * (0.015243699999999999 + (fSlow9 + fSlow8)));
	double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
	double 	fSlow12 = (fConst2 * fSlow6);
	double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
	double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
	double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
	double 	fSlow16 = fslider2;
	double 	fSlow17 = ((fSlow0 * (9.4752e-12 + fSlow4)) + (fSlow16 * (fSlow5 + (1.41e-10 - (1.41e-10 * fSlow0)))));
	double 	fSlow18 = (fConst2 * fSlow17);
	double 	fSlow19 = (4.764000000000001e-08 + (((9.187500000000001e-07 * fSlow16) + (fSlow0 * (1.2265872000000003e-07 - fSlow1))) + (fSlow2 * (2.48125e-06 + (5.6541000000000015e-06 * fSlow0)))));
	double 	fSlow20 = (0.00048120000000000004 + (fSlow9 + (fSlow8 + (6.25e-05 * fSlow16))));
	double 	fSlow21 = (fConst0 * fSlow20);
	double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
	double 	fSlow23 = (fConst0 * fSlow17);
	double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
	double 	fSlow25 = (fConst0 * (0 - fSlow20));
	double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
	double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
	for (uint32_t i=0; i<n_samples; i++) {
		fRec0[0] = ((double)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
		output[i] = (FAUSTFLOAT)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
		// post processing
		for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
	}
}

inline void TonestackMono::run_gibson(uint32_t n_samples, float *output )  //Gibson GA15
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;

	float 	fSlow0 = fslider0;
	float 	fSlow1 = (2.7131558400000005e-06f * fSlow0);
	float 	fSlow2 = expf((3.4f * (fslider1 - 1)));
	float 	fSlow3 = (1.3125756000000002e-05f + ((0.00012089350000000002f * fSlow2) + (fSlow0 * (((2.8262040000000004e-05f * fSlow2) - 8.450208960000001e-06f) - fSlow1))));
	float 	fSlow4 = ((3.53628e-09f * fSlow2) - (3.3948288e-10f * fSlow0));
	float 	fSlow5 = (1.21495e-08f * fSlow2);
	float 	fSlow6 = (1.166352e-09f + (fSlow5 + (fSlow0 * (fSlow4 - 8.268691200000001e-10f))));
	float 	fSlow7 = (fConst0 * fSlow6);
	float 	fSlow8 = (0.001128f * fSlow0);
	float 	fSlow9 = (0.025055f * fSlow2);
	float 	fSlow10 = (fConst0 * (0.01720868f + (fSlow9 + fSlow8)));
	float 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
	float 	fSlow12 = (fConst2 * fSlow6);
	float 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
	float 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
	float 	fSlow15 = (1.0f / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
	float 	fSlow16 = fslider2;
	float 	fSlow17 = ((fSlow0 * (3.3948288e-10f + fSlow4)) + (fSlow16 * (fSlow5 + (1.166352e-09f - (1.166352e-09f * fSlow0)))));
	float 	fSlow18 = (fConst2 * fSlow17);
	float 	fSlow19 = (3.25776e-07f + (((1.51998e-06f * fSlow16) + (fSlow0 * (2.8297910400000005e-06f - fSlow1))) + (fSlow2 * (3.3934999999999998e-06f + (2.8262040000000004e-05f * fSlow0)))));
	float 	fSlow20 = (0.00240528f + (fSlow9 + (fSlow8 + (0.00010339999999999999f * fSlow16))));
	float 	fSlow21 = (fConst0 * fSlow20);
	float 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
	float 	fSlow23 = (fConst0 * fSlow17);
	float 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
	float 	fSlow25 = (fConst0 * (0 - fSlow20));
	float 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
	float 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
	for (uint32_t i=0; i<n_samples; i++) {
		fRec0[0] = ((float)output[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
		output[i] = (FAUSTFLOAT)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
		// post processing
		for (int i=3; i>0; i--) fRec0[i] = fRec0[i-1];
	}
}

void TonestackMono::init_static(uint32_t samplingFreq, TonestackMono *p)
{
  p->init(samplingFreq);
}

void TonestackMono::connect_static(uint32_t port,void* data, TonestackMono *p)
{
  p->connect(port, data);
}

////////////////////////////// STEREO //////////////////////////////////


inline void TonestackStereo::clear_state_f()
{
  for (int32_t i=0; i<4; i++) fRec0[i] = 0;
  for (int32_t i=0; i<4; i++) fRec1[i] = 0;
}


inline void TonestackStereo::init(uint32_t  samplingFreq)
{
  fSamplingFreq = samplingFreq;
  fConst0 = (2 * double(min(192000, max(1, fSamplingFreq))));
  fConst1 = faustpower<2>(fConst0);
  fConst2 = (3 * fConst0);
  clear_state_f();
}


void TonestackStereo::connect(uint32_t port,void* data)
{
  switch ((PortIndex)port)
    {
    case MID:
      fslider0_ = (float*)data;
      break;
    case BASS:
      fslider1_ = (float*)data;
      break;
    case TREBLE:
      fslider2_ = (float*)data;
      break;
    default:
      break;
    }
}

inline void TonestackStereo::run(uint32_t count, float *output0, float *output1)
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;
  double 	fSlow0 = fslider0;
  double 	fSlow1 = (4.9434000000000004e-08 * fSlow0);
  double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
  double 	fSlow3 = (7.748796000000001e-07 + ((2.8889960000000004e-05 * fSlow2) + (fSlow0 * (((4.943400000000001e-06 * fSlow2) - 1.2634599999999999e-07) - fSlow1))));
  double 	fSlow4 = ((1.2443156000000004e-09 * fSlow2) - (1.2443156000000002e-11 * fSlow0));
  double 	fSlow5 = (5.345780000000001e-09 * fSlow2);
  double 	fSlow6 = (5.345780000000001e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 4.101464400000001e-11))));
  double 	fSlow7 = (fConst0 * fSlow6);
  double 	fSlow8 = (0.00022 * fSlow0);
  double 	fSlow9 = (0.022470000000000004 * fSlow2);
  double 	fSlow10 = (fConst0 * (0.0025277 + (fSlow9 + fSlow8)));
  double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
  double 	fSlow12 = (fConst2 * fSlow6);
  double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
  double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
  double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
  double 	fSlow16 = fslider2;
  double 	fSlow17 = ((fSlow0 * (1.2443156000000002e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (5.345780000000001e-11 - (5.345780000000001e-11 * fSlow0)))));
  double 	fSlow18 = (fConst2 * fSlow17);
  double 	fSlow19 = (6.141960000000001e-08 + (((4.859800000000001e-07 * fSlow16) + (fSlow0 * (1.0113400000000001e-07 - fSlow1))) + (fSlow2 * (6.141960000000001e-06 + (4.943400000000001e-06 * fSlow0)))));
  double 	fSlow20 = (0.00022470000000000001 + (fSlow9 + (fSlow8 + (0.00023500000000000002 * fSlow16))));
  double 	fSlow21 = (fConst0 * fSlow20);
  double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
  double 	fSlow23 = (fConst0 * fSlow17);
  double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
  double 	fSlow25 = (fConst0 * (0 - fSlow20));
  double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
  double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
  for (uint32_t i=0; i<count; i++)
    {
      fRec0[0] = ((double)output0[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
      output0[i] = (float)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
      fRec1[0] = ((double)output1[i] - (fSlow15 * (((fSlow14 * fRec1[2]) + (fSlow13 * fRec1[1])) + (fSlow11 * fRec1[3]))));
      output1[i] = (float)(fSlow15 * ((fSlow27 * fRec1[0]) + ((fSlow26 * fRec1[1]) + ((fSlow24 * fRec1[3]) + (fSlow22 * fRec1[2])))));
      // post processing
      for (int32_t i=3; i>0; i--) fRec1[i] = fRec1[i-1];
      for (int32_t i=3; i>0; i--) fRec0[i] = fRec0[i-1];
    }
}


inline void TonestackStereo::run_soldano(uint32_t count, float *output0, float *output1) //soldano
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;
  double 	fSlow0 = fslider0;
  double 	fSlow1 = (2.5587500000000006e-07 * fSlow0);
  double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
  double 	fSlow3 = (7.717400000000001e-07 + ((2.2033600000000005e-05 * fSlow2) + (fSlow0 * (((1.0235000000000001e-05 * fSlow2) - 1.5537499999999997e-07) - fSlow1))));
  double 	fSlow4 = ((1.3959000000000001e-09 * fSlow2) - (3.48975e-11 * fSlow0));
  double 	fSlow5 = (2.2090000000000005e-09 * fSlow2);
  double 	fSlow6 = (5.522500000000001e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 2.0327500000000007e-11))));
  double 	fSlow7 = (fConst0 * fSlow6);
  double 	fSlow8 = (0.0005 * fSlow0);
  double 	fSlow9 = (0.020470000000000002 * fSlow2);
  double 	fSlow10 = (fConst0 * (0.0025092499999999998 + (fSlow9 + fSlow8)));
  double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
  double 	fSlow12 = (fConst2 * fSlow6);
  double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
  double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
  double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
  double 	fSlow16 = fslider2;
  double 	fSlow17 = ((fSlow0 * (3.48975e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (5.522500000000001e-11 - (5.522500000000001e-11 * fSlow0)))));
  double 	fSlow18 = (fConst2 * fSlow17);
  double 	fSlow19 = (8.084000000000001e-08 + (((2.2090000000000003e-07 * fSlow16) + (fSlow0 * (3.146250000000001e-07 - fSlow1))) + (fSlow2 * (3.2336000000000007e-06 + (1.0235000000000001e-05 * fSlow0)))));
  double 	fSlow20 = (0.00051175 + (fSlow9 + (fSlow8 + (0.00011750000000000001 * fSlow16))));
  double 	fSlow21 = (fConst0 * fSlow20);
  double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
  double 	fSlow23 = (fConst0 * fSlow17);
  double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
  double 	fSlow25 = (fConst0 * (0 - fSlow20));
  double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
  double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
  for (uint32_t i=0; i<count; i++)
    {
      fRec0[0] = ((double)output0[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
      output0[i] = (float)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
      fRec1[0] = ((double)output1[i] - (fSlow15 * (((fSlow14 * fRec1[2]) + (fSlow13 * fRec1[1])) + (fSlow11 * fRec1[3]))));
      output1[i] = (float)(fSlow15 * ((fSlow27 * fRec1[0]) + ((fSlow26 * fRec1[1]) + ((fSlow24 * fRec1[3]) + (fSlow22 * fRec1[2])))));
      // post processing
      for (int32_t i=3; i>0; i--) fRec1[i] = fRec1[i-1];
      for (int32_t i=3; i>0; i--) fRec0[i] = fRec0[i-1];
    }
}

inline void TonestackStereo::run_bassman(uint32_t count, float *output0, float *output1) // bassman
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;
  double 	fSlow0 = fslider0;
  double 	fSlow1 = (2.5312500000000006e-07 * fSlow0);
  double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
  double 	fSlow3 = (7.4525e-07 + ((2.4210000000000004e-05 * fSlow2) + (fSlow0 * (((1.0125e-05 * fSlow2) - 2.75625e-07) - fSlow1))));
  double 	fSlow4 = ((7.650000000000002e-10 * fSlow2) - (1.9125000000000002e-11 * fSlow0));
  double 	fSlow5 = (1.4000000000000001e-09 * fSlow2);
  double 	fSlow6 = (3.500000000000001e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 1.5875000000000007e-11))));
  double 	fSlow7 = (fConst0 * fSlow6);
  double 	fSlow8 = (0.0005 * fSlow0);
  double 	fSlow9 = (0.02025 * fSlow2);
  double 	fSlow10 = (fConst0 * (0.0028087500000000005 + (fSlow9 + fSlow8)));
  double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
  double 	fSlow12 = (fConst2 * fSlow6);
  double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
  double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
  double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
  double 	fSlow16 = fslider2;
  double 	fSlow17 = ((fSlow0 * (1.9125000000000002e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (3.500000000000001e-11 - (3.500000000000001e-11 * fSlow0)))));
  double 	fSlow18 = (fConst2 * fSlow17);
  double 	fSlow19 = (4.525e-08 + (((1.4e-07 * fSlow16) + (fSlow0 * (2.8437500000000003e-07 - fSlow1))) + (fSlow2 * (1.8100000000000002e-06 + (1.0125e-05 * fSlow0)))));
  double 	fSlow20 = (0.00050625 + (fSlow9 + (fSlow8 + (6.25e-05 * fSlow16))));
  double 	fSlow21 = (fConst0 * fSlow20);
  double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
  double 	fSlow23 = (fConst0 * fSlow17);
  double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
  double 	fSlow25 = (fConst0 * (0 - fSlow20));
  double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
  double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
  for (uint32_t i=0; i<count; i++)
    {
      fRec0[0] = ((double)output0[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
      output0[i] = (float)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
      fRec1[0] = ((double)output1[i] - (fSlow15 * (((fSlow14 * fRec1[2]) + (fSlow13 * fRec1[1])) + (fSlow11 * fRec1[3]))));
      output1[i] = (float)(fSlow15 * ((fSlow27 * fRec1[0]) + ((fSlow26 * fRec1[1]) + ((fSlow24 * fRec1[3]) + (fSlow22 * fRec1[2])))));
      // post processing
      for (int32_t i=3; i>0; i--) fRec1[i] = fRec1[i-1];
      for (int32_t i=3; i>0; i--) fRec0[i] = fRec0[i-1];
    }
}

inline void TonestackStereo::run_ampeg(uint32_t count, float *output0, float *output1)  //ampeg
{
  float fslider0 = *fslider0_;
  float fslider1 = *fslider1_;
  float fslider2 = *fslider2_;

  double 	fSlow0 = fslider0;
  double 	fSlow1 = (3.0896250000000005e-07 * fSlow0);
  double 	fSlow2 = exp((3.4 * (fslider1 - 1)));
  double 	fSlow3 = (6.338090000000001e-07 + ((1.8734760000000003e-05 * fSlow2) + (fSlow0 * (((1.2358500000000002e-05 * fSlow2) - 1.361249999999999e-08) - fSlow1))));
  double 	fSlow4 = ((1.6037340000000005e-09 * fSlow2) - (4.0093350000000015e-11 * fSlow0));
  double 	fSlow5 = (1.8198400000000004e-09 * fSlow2);
  double 	fSlow6 = (4.5496000000000015e-11 + (fSlow5 + (fSlow0 * (fSlow4 - 5.40265e-12))));
  double 	fSlow7 = (fConst0 * fSlow6);
  double 	fSlow8 = (0.00055 * fSlow0);
  double 	fSlow9 = (0.022470000000000004 * fSlow2);
  double 	fSlow10 = (fConst0 * (0.00208725 + (fSlow9 + fSlow8)));
  double 	fSlow11 = ((fSlow10 + (fConst1 * (fSlow7 - fSlow3))) - 1);
  double 	fSlow12 = (fConst2 * fSlow6);
  double 	fSlow13 = ((fConst1 * (fSlow3 + fSlow12)) - (3 + fSlow10));
  double 	fSlow14 = ((fSlow10 + (fConst1 * (fSlow3 - fSlow12))) - 3);
  double 	fSlow15 = (1.0 / (0 - (1 + (fSlow10 + (fConst1 * (fSlow3 + fSlow7))))));
  double 	fSlow16 = fslider2;
  double 	fSlow17 = ((fSlow0 * (4.0093350000000015e-11 + fSlow4)) + (fSlow16 * (fSlow5 + (4.5496000000000015e-11 - (4.5496000000000015e-11 * fSlow0)))));
  double 	fSlow18 = (fConst2 * fSlow17);
  double 	fSlow19 = (8.1169e-08 + (((1.6544000000000003e-07 * fSlow16) + (fSlow0 * (3.735875000000001e-07 - fSlow1))) + (fSlow2 * (3.24676e-06 + (1.2358500000000002e-05 * fSlow0)))));
  double 	fSlow20 = (0.0005617500000000001 + (fSlow9 + (fSlow8 + (0.00011750000000000001 * fSlow16))));
  double 	fSlow21 = (fConst0 * fSlow20);
  double 	fSlow22 = (fSlow21 + (fConst1 * (fSlow19 - fSlow18)));
  double 	fSlow23 = (fConst0 * fSlow17);
  double 	fSlow24 = (fSlow21 + (fConst1 * (fSlow23 - fSlow19)));
  double 	fSlow25 = (fConst0 * (0 - fSlow20));
  double 	fSlow26 = (fSlow25 + (fConst1 * (fSlow19 + fSlow18)));
  double 	fSlow27 = (fSlow25 - (fConst1 * (fSlow19 + fSlow23)));
  for (uint32_t i=0; i<count; i++)
    {
      fRec0[0] = ((double)output0[i] - (fSlow15 * (((fSlow14 * fRec0[2]) + (fSlow13 * fRec0[1])) + (fSlow11 * fRec0[3]))));
      output0[i] = (float)(fSlow15 * ((fSlow27 * fRec0[0]) + ((fSlow26 * fRec0[1]) + ((fSlow24 * fRec0[3]) + (fSlow22 * fRec0[2])))));
      fRec1[0] = ((double)output1[i] - (fSlow15 * (((fSlow14 * fRec1[2]) + (fSlow13 * fRec1[1])) + (fSlow11 * fRec1[3]))));
      output1[i] = (float)(fSlow15 * ((fSlow27 * fRec1[0]) + ((fSlow26 * fRec1[1]) + ((fSlow24 * fRec1[3]) + (fSlow22 * fRec1[2])))));
      // post processing
      for (int32_t i=3; i>0; i--) fRec1[i] = fRec1[i-1];
      for (int32_t i=3; i>0; i--) fRec0[i] = fRec0[i-1];
    }
}



void TonestackStereo::init_static(uint32_t samplingFreq, TonestackStereo *p)
{
  p->init(samplingFreq);
}

void TonestackStereo::connect_static(uint32_t port,void* data, TonestackStereo *p)
{
  p->connect(port, data);
}
