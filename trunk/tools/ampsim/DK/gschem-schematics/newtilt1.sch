v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 41800 45800 1 180 0 resistor-2.sym
{
T 41400 45450 5 10 0 0 180 0 1
device=RESISTOR
T 41316 45534 5 10 1 1 180 0 1
refdes=R2
T 41400 45400 5 10 1 1 0 0 1
value=68k
}
C 42700 44800 1 270 0 resistor-2.sym
{
T 43050 44400 5 10 0 0 270 0 1
device=RESISTOR
T 43000 44500 5 10 1 1 0 0 1
refdes=R3
T 43000 44300 5 10 1 1 0 0 1
value=1k5
}
C 42500 48300 1 270 0 resistor-2.sym
{
T 42850 47900 5 10 0 0 270 0 1
device=RESISTOR
T 42800 47900 5 10 1 1 0 0 1
refdes=R4
T 42800 47700 5 10 1 1 0 0 1
value=100k
}
C 44900 46800 1 0 0 capacitor-1.sym
{
T 45100 47500 5 10 0 0 0 0 1
device=CAPACITOR
T 45200 47300 5 10 1 1 0 0 1
refdes=C3
T 45100 47700 5 10 0 0 0 0 1
symversion=0.1
T 45200 46600 5 10 1 1 0 0 1
value=22n
}
C 40800 44100 1 0 0 gnd-1.sym
C 40200 43700 1 0 0 triode.sym
{
T 43000 46500 5 10 1 1 0 0 1
refdes=U1
T 42900 46200 5 10 1 1 0 0 1
value=12ax7
T 42600 45800 5 10 0 1 0 0 1
device=TRIODE
}
C 40100 45600 1 0 0 input-1.sym
{
T 40100 45900 5 10 0 0 0 0 1
device=INPUT
T 40227 45634 5 10 1 1 0 0 1
refdes=Vin
}
C 42700 43200 1 0 0 gnd-1.sym
C 44000 46800 1 0 0 ccurrent.sym
{
T 44200 47300 5 10 1 1 0 0 1
refdes=CC1
T 44400 47100 5 10 0 1 0 0 1
device=CONNECTION_CURRENT
}
N 44000 47000 42600 47000 4
{
T 43700 47100 5 10 1 1 0 0 1
netname=4
}
C 42400 48500 1 0 0 generic-power-1.sym
{
T 42600 48700 5 10 0 1 0 0 1
device=POWER
T 42932 48749 5 10 1 1 0 0 1
value=150V
T 42409 48752 5 10 1 1 0 0 1
refdes=Vcc1
}
N 42800 43500 42800 43900 4
N 42800 44800 42800 45000 4
N 42600 48500 42600 48300 4
{
T 42400 48400 5 10 1 1 0 0 1
netname=5
}
N 42600 46500 42600 47400 4
N 44900 47000 44800 47000 4
{
T 44800 47100 5 10 1 1 0 0 1
netname=6
}
N 45800 47000 46200 47000 4
C 41000 44500 1 90 0 resistor-1.sym
{
T 40600 44800 5 10 0 0 90 0 1
device=RESISTOR
T 40700 44700 5 10 1 1 90 0 1
refdes=R5
T 41000 44500 5 10 1 1 0 0 1
value=1M
}
N 40900 45700 40900 45400 4
N 40900 44500 40900 44400 4
C 48500 43300 1 0 0 gnd-1.sym
N 48600 43600 48600 45400 4
C 48500 46300 1 270 0 resistor-variable-2.sym
{
T 49400 45500 5 10 0 1 270 0 1
device=VARIABLE_RESISTOR
T 48210 45902 5 10 1 1 0 0 1
refdes=P3
T 48500 46300 5 10 1 1 0 0 1
value=value=1M,var=Drive,a=1,inv=1
}
C 46500 47300 1 0 0 capacitor-1.sym
{
T 46700 48000 5 10 0 0 0 0 1
device=CAPACITOR
T 46700 48200 5 10 0 0 0 0 1
symversion=0.1
T 46800 47800 5 10 1 1 0 0 1
refdes=C8
T 46700 47100 5 10 1 1 0 0 1
value=0.012u
}
C 47600 45700 1 90 0 capacitor-1.sym
{
T 46900 45900 5 10 0 0 90 0 1
device=CAPACITOR
T 46700 45900 5 10 0 0 90 0 1
symversion=0.1
T 47100 45900 5 10 1 1 90 0 1
refdes=C7
T 47600 46200 5 10 1 1 0 0 1
value=0.01u
}
C 46400 46500 1 0 0 resistor-2.sym
{
T 46800 46850 5 10 0 0 0 0 1
device=RESISTOR
T 46600 46500 5 10 1 1 0 0 1
refdes=R11
T 46600 46300 5 10 1 1 0 0 1
value=39k
}
C 47500 47500 1 90 0 resistor-2.sym
{
T 47150 47900 5 10 0 0 90 0 1
device=RESISTOR
T 47500 47800 5 10 1 1 90 0 1
refdes=R10
T 47700 47800 5 10 1 1 90 0 1
value=5k6
}
C 47300 46600 1 270 1 resistor-variable-2.sym
{
T 48200 47400 5 10 0 1 90 2 1
device=VARIABLE_RESISTOR
T 47700 47150 5 10 1 1 90 2 1
refdes=P5
T 47300 46600 5 10 1 1 0 0 1
value=value=100k,var=Tone,a=1
}
C 47300 45400 1 0 0 gnd-1.sym
C 50300 48500 1 90 1 gnd-1.sym
N 47900 47100 48600 47100 4
N 48600 47100 48600 46300 4
N 46500 47500 46200 47500 4
N 46200 46600 46200 47500 4
N 46400 46600 46200 46600 4
N 47600 48400 47400 48400 4
C 47600 48300 1 0 0 resistor-variable-2.sym
{
T 48400 49200 5 10 0 1 0 0 1
device=VARIABLE_RESISTOR
T 48150 48700 5 10 1 1 0 0 1
refdes=P2
T 47300 49000 5 10 1 1 0 0 1
value=value=25k,var=Body
}
N 48500 48400 50000 48400 4
N 48100 48900 50000 48900 4
N 50000 48900 50000 48400 4
N 47300 46600 47400 46600 4
C 50800 48400 1 270 0 resistor-2.sym
{
T 51150 48000 5 10 0 0 270 0 1
device=RESISTOR
T 51100 48000 5 10 1 1 0 0 1
refdes=R8
T 51100 47800 5 10 1 1 0 0 1
value=100k
}
C 51000 44900 1 270 0 resistor-2.sym
{
T 51350 44500 5 10 0 0 270 0 1
device=RESISTOR
T 50600 44500 5 10 1 1 0 0 1
refdes=R7
T 50600 44300 5 10 1 1 0 0 1
value=820
}
C 52700 46900 1 0 0 capacitor-1.sym
{
T 52900 47600 5 10 0 0 0 0 1
device=CAPACITOR
T 52900 47800 5 10 0 0 0 0 1
symversion=0.1
T 53000 47400 5 10 1 1 0 0 1
refdes=C6
T 53000 46700 5 10 1 1 0 0 1
value=100n
}
C 51000 43300 1 0 0 gnd-1.sym
C 48500 43800 1 0 0 triode.sym
{
T 51400 46300 5 10 1 1 0 0 1
refdes=U2
T 51400 46000 5 10 1 1 0 0 1
value=12au7
}
C 50700 48600 1 0 0 generic-power-1.sym
{
T 48900 48700 5 10 0 1 0 0 1
device=POWER
T 51234 48852 5 10 1 1 0 0 1
value=250V
T 50695 48848 5 10 1 1 0 0 1
refdes=Vcc2
}
C 51700 46900 1 0 0 ccurrent.sym
{
T 52100 47200 5 10 0 1 0 0 1
device=CONNECTION_CURRENT
T 51900 47400 5 10 1 1 0 0 1
refdes=CC2
}
N 50900 46600 50900 47500 4
N 50900 47100 51700 47100 4
{
T 51200 47200 5 10 1 1 0 0 1
netname=11
}
C 56000 46600 1 0 0 output-1.sym
{
T 56100 46900 5 10 0 0 0 0 1
device=OUTPUT
T 56289 46637 5 10 1 1 0 0 1
refdes=Vout
}
N 52700 47100 52500 47100 4
{
T 52500 47200 5 10 1 1 0 0 1
netname=13
}
N 51100 43600 51100 44000 4
N 51100 44900 51100 45100 4
{
T 50800 45000 5 10 1 1 0 0 1
netname=10
}
N 50900 48600 50900 48400 4
{
T 50600 48500 5 10 1 1 0 0 1
netname=12
}
N 54500 47100 53600 47100 4
C 55400 45900 1 0 0 gnd-1.sym
C 55400 46200 1 270 1 resistor-variable-2.sym
{
T 56300 47000 5 10 0 1 90 2 1
device=VARIABLE_RESISTOR
T 55800 46750 5 10 1 1 90 2 1
refdes=P6
T 55000 46100 5 10 1 1 0 0 1
value=value=1M,var=Level,a=1
}
T 54000 47100 8 10 1 1 0 0 1
netname=14
C 49200 45700 1 0 0 resistor-2.sym
{
T 49600 46050 5 10 0 0 0 0 1
device=RESISTOR
T 49400 46000 5 10 1 1 0 0 1
refdes=R13
T 49400 45400 5 10 1 1 0 0 1
value=100k
}
N 49200 45800 49100 45800 4
C 43700 44800 1 270 0 capacitor-2.sym
{
T 44400 44600 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 44200 44600 5 10 1 1 270 0 1
refdes=CNew
T 44600 44600 5 10 0 0 270 0 1
symversion=0.1
T 43700 44800 5 10 1 1 270 0 1
value=22u
}
N 42800 44800 43900 44800 4
N 43900 43900 42800 43900 4
C 54500 47000 1 0 0 resistor-2.sym
{
T 54900 47350 5 10 0 0 0 0 1
device=RESISTOR
T 54700 47300 5 10 1 1 0 0 1
refdes=R9
T 54700 47000 5 10 1 1 0 0 1
value=3.3M
}
N 55400 47100 55500 47100 4