#pragma once

#include <vector>
#include <string>
using namespace std;
struct stage_data
{
    int enemy_x;
    int enemy_y;
    vector<int> pattern;
    int enemy_health;
    string bulletype;
};//�� �Ѹ��� ��ġ


extern vector<vector<stage_data>> Every_Stage;