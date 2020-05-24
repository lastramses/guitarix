
// alembic_out_neg_table generated by DK/circ_table_gen.py -- do not modify manually

 // variables used
 // --sig_max  -3.000000
 // --table_div  92.013825
 // --table_op  0.250000

struct tablealembic_out_neg { // 1-dimensional function table
    float low;
    float high;
    float istep;
    int size;
    float data[];
};

template <int tab_size>
struct tablealembic_out_neg_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
    operator tablealembic_out_neg&() const { return *(tablealembic_out_neg*)this; }
};

 static tablealembic_out_neg_imp<200> alembic_out_neg_table __rt_data = {
	0,0.388692,16.5833,200, {
	0.000000000000,0.004791170118,0.009562118140,0.014312633699,0.019042505689,
	0.023751522214,0.028439470554,0.033106137116,0.037751307401,0.042374765953,
	0.046976296330,0.051555681058,0.056112701594,0.060647138294,0.065158770368,
	0.069647375855,0.074112731581,0.078554613132,0.082972794822,0.087367049664,
	0.091737149342,0.096082864186,0.100403963149,0.104700213786,0.108971382234,
	0.113217233197,0.117437529930,0.121632034231,0.125800506431,0.129942705388,
	0.134058388490,0.138147311652,0.142209229328,0.146243894514,0.150251058769,
	0.154230472229,0.158181883635,0.162105040358,0.165999688436,0.169865572614,
	0.173702436387,0.177510022056,0.181288070782,0.185036322659,0.188754516779,
	0.192442391318,0.196099683624,0.199726130312,0.203321467373,0.206885430286,
	0.210417754146,0.213918173798,0.217386423979,0.220822239480,0.224225355308,
	0.227595506869,0.230932430156,0.234235861955,0.237505540061,0.240741203510,
	0.243942592816,0.247109450238,0.250241520045,0.253338548807,0.256400285694,
	0.259426482795,0.262416895452,0.265371282605,0.268289407159,0.271171036360,
	0.274015942198,0.276823901810,0.279594697915,0.282328119249,0.285023961030,
	0.287682025425,0.290302122038,0.292884068411,0.295427690535,0.297932823373,
	0.300399311398,0.302827009138,0.305215781723,0.307565505451,0.309876068352,
	0.312147370751,0.314379325845,0.316571860267,0.318724914652,0.320838444203,
	0.322912419236,0.324946825732,0.326941665857,0.328896958480,0.330812739667,
	0.332689063148,0.334526000766,0.336323642892,0.338082098810,0.339801497064,
	0.341481985771,0.343123732886,0.344726926431,0.346291774665,0.347818506213,
	0.349307370136,0.350758635952,0.352172593588,0.353549553290,0.354889845454,
	0.356193820407,0.357461848124,0.358694317878,0.359891637834,0.361054234573,
	0.362182552560,0.363277053558,0.364338215969,0.365366534137,0.366362517588,
	0.367326690226,0.368259589476,0.369161765399,0.370033779755,0.370876205043,
	0.371689623508,0.372474626125,0.373231811573,0.373961785179,0.374665157875,
	0.375342545135,0.375994565926,0.376621841658,0.377224995158,0.377804649648,
	0.378361427751,0.378895950528,0.379408836531,0.379900700907,0.380372154517,
	0.380823803116,0.381256246559,0.381670078057,0.382065883475,0.382444240685,
	0.382805718954,0.383150878388,0.383480269429,0.383794432385,0.384093897025,
	0.384379182212,0.384650795581,0.384909233271,0.385154979691,0.385388507337,
	0.385610276642,0.385820735870,0.386020321049,0.386209455932,0.386388551994,
	0.386558008467,0.386718212391,0.386869538701,0.387012350337,0.387146998372,
	0.387273822169,0.387393149546,0.387505296965,0.387610569737,0.387709262231,
	0.387801658104,0.387888030534,0.387968642465,0.388043746858,0.388113586945,
	0.388178396490,0.388238400053,0.388293813250,0.388344843024,0.388391687908,
	0.388434538288,0.388473576669,0.388508977933,0.388540909600,0.388569532078,
	0.388594998918,0.388617457055,0.388637047054,0.388653903344,0.388668154451,
	0.388679923219,0.388689327037,0.388696478047,0.388701483355,0.388704445232,
	0.388705461314,0.388704624788,0.388702024575,0.388697745516,0.388691868535
	}
};

double always_inline alembic_out_negclip(double x) {
    double f = fabs(x);
    f = f * alembic_out_neg_table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = alembic_out_neg_table.data[0];
    } else if (i >= alembic_out_neg_table.size-1) {
        f = alembic_out_neg_table.data[alembic_out_neg_table.size-1];
    } else {
    f -= i;
    f = alembic_out_neg_table.data[i]*(1-f) + alembic_out_neg_table.data[i+1]*f;
    }
    return copysign(f, x);
}
