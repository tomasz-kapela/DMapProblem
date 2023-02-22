/*
 * DagIndexer.cpp
 *
 *  Created on: Aug 25, 2012
 *      Author: kapela
 */


#include "capd/autodiff/DagIndexer.hpp"

namespace capd{
namespace autodiff{

__size_type capd_c2jet_indices[21][20][20]={
{},
{{2}},
{{3,4},{4,5}},
{{4,5,6},{5,7,8},{6,8,9}},
{{5,6,7,8},{6,9,10,11},{7,10,12,13},{8,11,13,14}},
{{6,7,8,9,10},{7,11,12,13,14},{8,12,15,16,17},{9,13,16,18,19},{10,14,17,19,20}},
{{7,8,9,10,11,12},{8,13,14,15,16,17},{9,14,18,19,20,21},{10,15,19,22,23,24},{11,16,20,23,25,26},{12,17,21,24,26,27}},
{{8,9,10,11,12,13,14},{9,15,16,17,18,19,20},{10,16,21,22,23,24,25},{11,17,22,26,27,28,29},{12,18,23,27,30,31,32},{13,19,24,28,31,33,34},{14,20,25,29,32,34,35}},
{{9,10,11,12,13,14,15,16},{10,17,18,19,20,21,22,23},{11,18,24,25,26,27,28,29},{12,19,25,30,31,32,33,34},{13,20,26,31,35,36,37,38},{14,21,27,32,36,39,40,41},{15,22,28,33,37,40,42,43},{16,23,29,34,38,41,43,44}},
{{10,11,12,13,14,15,16,17,18},{11,19,20,21,22,23,24,25,26},{12,20,27,28,29,30,31,32,33},{13,21,28,34,35,36,37,38,39},{14,22,29,35,40,41,42,43,44},{15,23,30,36,41,45,46,47,48},{16,24,31,37,42,46,49,50,51},{17,25,32,38,43,47,50,52,53},{18,26,33,39,44,48,51,53,54}},
{{11,12,13,14,15,16,17,18,19,20},{12,21,22,23,24,25,26,27,28,29},{13,22,30,31,32,33,34,35,36,37},{14,23,31,38,39,40,41,42,43,44},{15,24,32,39,45,46,47,48,49,50},{16,25,33,40,46,51,52,53,54,55},{17,26,34,41,47,52,56,57,58,59},{18,27,35,42,48,53,57,60,61,62},{19,28,36,43,49,54,58,61,63,64},{20,29,37,44,50,55,59,62,64,65}},
{{12,13,14,15,16,17,18,19,20,21,22},{13,23,24,25,26,27,28,29,30,31,32},{14,24,33,34,35,36,37,38,39,40,41},{15,25,34,42,43,44,45,46,47,48,49},{16,26,35,43,50,51,52,53,54,55,56},{17,27,36,44,51,57,58,59,60,61,62},{18,28,37,45,52,58,63,64,65,66,67},{19,29,38,46,53,59,64,68,69,70,71},{20,30,39,47,54,60,65,69,72,73,74},{21,31,40,48,55,61,66,70,73,75,76},{22,32,41,49,56,62,67,71,74,76,77}},
{{13,14,15,16,17,18,19,20,21,22,23,24},{14,25,26,27,28,29,30,31,32,33,34,35},{15,26,36,37,38,39,40,41,42,43,44,45},{16,27,37,46,47,48,49,50,51,52,53,54},{17,28,38,47,55,56,57,58,59,60,61,62},{18,29,39,48,56,63,64,65,66,67,68,69},{19,30,40,49,57,64,70,71,72,73,74,75},{20,31,41,50,58,65,71,76,77,78,79,80},{21,32,42,51,59,66,72,77,81,82,83,84},{22,33,43,52,60,67,73,78,82,85,86,87},{23,34,44,53,61,68,74,79,83,86,88,89},{24,35,45,54,62,69,75,80,84,87,89,90}},
{{14,15,16,17,18,19,20,21,22,23,24,25,26},{15,27,28,29,30,31,32,33,34,35,36,37,38},{16,28,39,40,41,42,43,44,45,46,47,48,49},{17,29,40,50,51,52,53,54,55,56,57,58,59},{18,30,41,51,60,61,62,63,64,65,66,67,68},{19,31,42,52,61,69,70,71,72,73,74,75,76},{20,32,43,53,62,70,77,78,79,80,81,82,83},{21,33,44,54,63,71,78,84,85,86,87,88,89},{22,34,45,55,64,72,79,85,90,91,92,93,94},{23,35,46,56,65,73,80,86,91,95,96,97,98},{24,36,47,57,66,74,81,87,92,96,99,100,101},{25,37,48,58,67,75,82,88,93,97,100,102,103},{26,38,49,59,68,76,83,89,94,98,101,103,104}},
{{15,16,17,18,19,20,21,22,23,24,25,26,27,28},{16,29,30,31,32,33,34,35,36,37,38,39,40,41},{17,30,42,43,44,45,46,47,48,49,50,51,52,53},{18,31,43,54,55,56,57,58,59,60,61,62,63,64},{19,32,44,55,65,66,67,68,69,70,71,72,73,74},{20,33,45,56,66,75,76,77,78,79,80,81,82,83},{21,34,46,57,67,76,84,85,86,87,88,89,90,91},{22,35,47,58,68,77,85,92,93,94,95,96,97,98},{23,36,48,59,69,78,86,93,99,100,101,102,103,104},{24,37,49,60,70,79,87,94,100,105,106,107,108,109},{25,38,50,61,71,80,88,95,101,106,110,111,112,113},{26,39,51,62,72,81,89,96,102,107,111,114,115,116},{27,40,52,63,73,82,90,97,103,108,112,115,117,118},{28,41,53,64,74,83,91,98,104,109,113,116,118,119}},
{{16,17,18,19,20,21,22,23,24,25,26,27,28,29,30},{17,31,32,33,34,35,36,37,38,39,40,41,42,43,44},{18,32,45,46,47,48,49,50,51,52,53,54,55,56,57},{19,33,46,58,59,60,61,62,63,64,65,66,67,68,69},{20,34,47,59,70,71,72,73,74,75,76,77,78,79,80},{21,35,48,60,71,81,82,83,84,85,86,87,88,89,90},{22,36,49,61,72,82,91,92,93,94,95,96,97,98,99},{23,37,50,62,73,83,92,100,101,102,103,104,105,106,107},{24,38,51,63,74,84,93,101,108,109,110,111,112,113,114},{25,39,52,64,75,85,94,102,109,115,116,117,118,119,120},{26,40,53,65,76,86,95,103,110,116,121,122,123,124,125},{27,41,54,66,77,87,96,104,111,117,122,126,127,128,129},{28,42,55,67,78,88,97,105,112,118,123,127,130,131,132},{29,43,56,68,79,89,98,106,113,119,124,128,131,133,134},{30,44,57,69,80,90,99,107,114,120,125,129,132,134,135}},
{{17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32},{18,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47},{19,34,48,49,50,51,52,53,54,55,56,57,58,59,60,61},{20,35,49,62,63,64,65,66,67,68,69,70,71,72,73,74},{21,36,50,63,75,76,77,78,79,80,81,82,83,84,85,86},{22,37,51,64,76,87,88,89,90,91,92,93,94,95,96,97},{23,38,52,65,77,88,98,99,100,101,102,103,104,105,106,107},{24,39,53,66,78,89,99,108,109,110,111,112,113,114,115,116},{25,40,54,67,79,90,100,109,117,118,119,120,121,122,123,124},{26,41,55,68,80,91,101,110,118,125,126,127,128,129,130,131},{27,42,56,69,81,92,102,111,119,126,132,133,134,135,136,137},{28,43,57,70,82,93,103,112,120,127,133,138,139,140,141,142},{29,44,58,71,83,94,104,113,121,128,134,139,143,144,145,146},{30,45,59,72,84,95,105,114,122,129,135,140,144,147,148,149},{31,46,60,73,85,96,106,115,123,130,136,141,145,148,150,151},{32,47,61,74,86,97,107,116,124,131,137,142,146,149,151,152}},
{{18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34},{19,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50},{20,36,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65},{21,37,52,66,67,68,69,70,71,72,73,74,75,76,77,78,79},{22,38,53,67,80,81,82,83,84,85,86,87,88,89,90,91,92},{23,39,54,68,81,93,94,95,96,97,98,99,100,101,102,103,104},{24,40,55,69,82,94,105,106,107,108,109,110,111,112,113,114,115},{25,41,56,70,83,95,106,116,117,118,119,120,121,122,123,124,125},{26,42,57,71,84,96,107,117,126,127,128,129,130,131,132,133,134},{27,43,58,72,85,97,108,118,127,135,136,137,138,139,140,141,142},{28,44,59,73,86,98,109,119,128,136,143,144,145,146,147,148,149},{29,45,60,74,87,99,110,120,129,137,144,150,151,152,153,154,155},{30,46,61,75,88,100,111,121,130,138,145,151,156,157,158,159,160},{31,47,62,76,89,101,112,122,131,139,146,152,157,161,162,163,164},{32,48,63,77,90,102,113,123,132,140,147,153,158,162,165,166,167},{33,49,64,78,91,103,114,124,133,141,148,154,159,163,166,168,169},{34,50,65,79,92,104,115,125,134,142,149,155,160,164,167,169,170}},
{{19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36},{20,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53},{21,38,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69},{22,39,55,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84},{23,40,56,71,85,86,87,88,89,90,91,92,93,94,95,96,97,98},{24,41,57,72,86,99,100,101,102,103,104,105,106,107,108,109,110,111},{25,42,58,73,87,100,112,113,114,115,116,117,118,119,120,121,122,123},{26,43,59,74,88,101,113,124,125,126,127,128,129,130,131,132,133,134},{27,44,60,75,89,102,114,125,135,136,137,138,139,140,141,142,143,144},{28,45,61,76,90,103,115,126,136,145,146,147,148,149,150,151,152,153},{29,46,62,77,91,104,116,127,137,146,154,155,156,157,158,159,160,161},{30,47,63,78,92,105,117,128,138,147,155,162,163,164,165,166,167,168},{31,48,64,79,93,106,118,129,139,148,156,163,169,170,171,172,173,174},{32,49,65,80,94,107,119,130,140,149,157,164,170,175,176,177,178,179},{33,50,66,81,95,108,120,131,141,150,158,165,171,176,180,181,182,183},{34,51,67,82,96,109,121,132,142,151,159,166,172,177,181,184,185,186},{35,52,68,83,97,110,122,133,143,152,160,167,173,178,182,185,187,188},{36,53,69,84,98,111,123,134,144,153,161,168,174,179,183,186,188,189}},
{{20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38},{21,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56},{22,40,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73},{23,41,58,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89},{24,42,59,75,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104},{25,43,60,76,91,105,106,107,108,109,110,111,112,113,114,115,116,117,118},{26,44,61,77,92,106,119,120,121,122,123,124,125,126,127,128,129,130,131},{27,45,62,78,93,107,120,132,133,134,135,136,137,138,139,140,141,142,143},{28,46,63,79,94,108,121,133,144,145,146,147,148,149,150,151,152,153,154},{29,47,64,80,95,109,122,134,145,155,156,157,158,159,160,161,162,163,164},{30,48,65,81,96,110,123,135,146,156,165,166,167,168,169,170,171,172,173},{31,49,66,82,97,111,124,136,147,157,166,174,175,176,177,178,179,180,181},{32,50,67,83,98,112,125,137,148,158,167,175,182,183,184,185,186,187,188},{33,51,68,84,99,113,126,138,149,159,168,176,183,189,190,191,192,193,194},{34,52,69,85,100,114,127,139,150,160,169,177,184,190,195,196,197,198,199},{35,53,70,86,101,115,128,140,151,161,170,178,185,191,196,200,201,202,203},{36,54,71,87,102,116,129,141,152,162,171,179,186,192,197,201,204,205,206},{37,55,72,88,103,117,130,142,153,163,172,180,187,193,198,202,205,207,208},{38,56,73,89,104,118,131,143,154,164,173,181,188,194,199,203,206,208,209}},
{{21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40},{22,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59},{23,42,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77},{24,43,61,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94},{25,44,62,79,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110},{26,45,63,80,96,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125},{27,46,64,81,97,112,126,127,128,129,130,131,132,133,134,135,136,137,138,139},{28,47,65,82,98,113,127,140,141,142,143,144,145,146,147,148,149,150,151,152},{29,48,66,83,99,114,128,141,153,154,155,156,157,158,159,160,161,162,163,164},{30,49,67,84,100,115,129,142,154,165,166,167,168,169,170,171,172,173,174,175},{31,50,68,85,101,116,130,143,155,166,176,177,178,179,180,181,182,183,184,185},{32,51,69,86,102,117,131,144,156,167,177,186,187,188,189,190,191,192,193,194},{33,52,70,87,103,118,132,145,157,168,178,187,195,196,197,198,199,200,201,202},{34,53,71,88,104,119,133,146,158,169,179,188,196,203,204,205,206,207,208,209},{35,54,72,89,105,120,134,147,159,170,180,189,197,204,210,211,212,213,214,215},{36,55,73,90,106,121,135,148,160,171,181,190,198,205,211,216,217,218,219,220},{37,56,74,91,107,122,136,149,161,172,182,191,199,206,212,217,221,222,223,224},{38,57,75,92,108,123,137,150,162,173,183,192,200,207,213,218,222,225,226,227},{39,58,76,93,109,124,138,151,163,174,184,193,201,208,214,219,223,226,228,229},{40,59,77,94,110,125,139,152,164,175,185,194,202,209,215,220,224,227,229,230}}};

}}

//template class capd::autodiff::DagIndexer<double>;
//template class capd::autodiff::DagIndexer<long double>;
