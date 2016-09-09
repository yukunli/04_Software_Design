

#include "ConstData_Table.h"

//����ͨ��4KHZ�����źŵĲο��������źţ�����Ƶ��120kHZ  
float sin_wave1[30]=
{
	0.0, 0.207911, 0.4067366, 0.5877852, 0.7431448, 0.8660254, 0.9510565, 0.9945219, 0.9945219, 0.9510565, 0.86602545, 0.7431449, 0.587785, 0.40673676, 0.2079118, 1.5358979e-07, -0.20791155, -0.40673648, -0.5877851, -0.74314469, -0.8660253, -0.9510564, -0.99452187, -0.9945219, -0.95105659, -0.8660255, -0.7431450, -0.58778547, -0.4067369, -0.2079119
};
float cos_wave1[30]=
{
	1.0, 0.9781476, 0.91354546, 0.8090170, 0.6691306, 0.5000, 0.30901705, 0.1045285, -0.10452838, -0.3090169, -0.49999, -0.6691305, -0.8090169, -0.9135454, -0.9781475, -0.99999999, -0.9781476, -0.9135455, -0.8090171, -0.66913075, -0.5000, -0.30901719, -0.10452868, 0.1045282, 0.30901676, 0.499999, 0.6691304, 0.8090168, 0.9135453, 0.9781475
};
//����ͨ��6KHZ�����źŵĲο��������źţ�����Ƶ��120kHZ 
float sin_wave2[20]=
{
	0.0, 0.30901697, 0.5877852, 0.8090169, 0.9510565, 0.999999, 0.9510565, 0.80901705, 0.58778535, 0.3090171, 1.5358979e-07, -0.3090168, -0.5877851, -0.8090169, -0.9510564, -0.9999999, -0.9510566, -0.8090171, -0.58778547, -0.30901727
};
float cos_wave2[20]=
{
	1.0, 0.9510565, 0.8090170, 0.58778528, 0.30901705, 7.6794896, -0.3090169, -0.58778516, -0.8090169, -0.95105647, -0.9999999, -0.95105656, -0.8090171, -0.5877854, -0.30901719, -2.3038469e-07, 0.30901676, 0.5877850, 0.8090168, 0.9510564
};
//����ͨ��8KHZ�����źŵĲο��������źţ�����Ƶ��120kHZ 
float sin_wave3[15]=
{
	0.0, 0.4067366, 0.7431448, 0.95105649, 0.9945219, 0.8660254, 0.5877853, 0.2079118, -0.20791153, -0.5877851, -0.8660253, -0.9945218, -0.9510565, -0.7431450, -0.4067369
};
float cos_wave3[15]=
{
	1.0, 0.91354546, 0.6691306, 0.30901705, -0.10452838, -0.499999, -0.8090169, -0.97814757, -0.9781476, -0.8090171, -0.500000, -0.10452868, 0.30901676, 0.6691304, 0.9135453
};


// 61�׵�ͨ�˲��� 210khz
_iq24 Low_Filter1[62] = {
    0.002829352627, 0.003547752276, 0.004316083156, 0.005131774116, 0.005991730373,
    0.006892347243, 0.007829532959, 0.00879873056,  0.009794953279, 0.01081281994,
    0.01184659451,  0.01289023552,  0.01393744349,  0.01498171408,  0.01601639949,
    0.01703476161,  0.01803003438,  0.01899549179,  0.01992449909,  0.02081058547,
    0.02164749801,  0.02242926694,  0.02315025777,  0.02380523272,  0.02438939176,
    0.02489842847,  0.02532857284,  0.0256766174,   0.0259399619,   0.02611663193,
    0.02620530128,  0.02620530128,  0.02611663193,  0.0259399619,   0.0256766174,
    0.02532857284,  0.02489842847,  0.02438939176,  0.02380523272,  0.02315025777,
    0.02242926694,  0.02164749801,  0.02081058547,  0.01992449909,  0.01899549179,
    0.01803003438,  0.01703476161,  0.01601639949,  0.01498171408,  0.01393744349,
    0.01289023552,  0.01184659451,  0.01081281994,  0.009794953279, 0.00879873056,
    0.007829532959, 0.006892347243, 0.005991730373, 0.005131774116, 0.004316083156,
    0.003547752276, 0.002829352627,
};

_iq24 Low_Filter2[37] = {
       0.02181138285, -0.02011265047, -0.01731494814, -0.01684645377, -0.01684641652,
   -0.01605831832, -0.01367643289,-0.009039154276,-0.002036049496, 0.007444297429,
    0.01911091246,  0.03240166605,  0.04661503807,  0.06088255346,  0.07430711389,
    0.08590719849,  0.09485333413,   0.1005149111,   0.1024425626,   0.1005149111,
    0.09485333413,  0.08590719849,  0.07430711389,  0.06088255346,  0.04661503807,
    0.03240166605,  0.01911091246, 0.007444297429,-0.002036049496,-0.009039154276,
   -0.01367643289, -0.01605831832, -0.01684641652, -0.01684645377, -0.01731494814,
   -0.02011265047,  0.02181138285
};

