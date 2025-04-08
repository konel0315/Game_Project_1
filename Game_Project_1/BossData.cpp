#include "BossData.h"

vector<BossData> BossTemplates = {
    {
        14, 5, // 기준점 startX, startY
        {1, -2, 1, 2, 1, -2, 1, 2, 1, -2, 1, 2, 1, -2, 1, 2, 1, -2, 1, 2, 1, -2, 1, 2,- 1, -2, -1, 2, -1, -2, -1, 2, -1, -2, -1, 2, -1, -2, -1, 2, -1, -2, -1, 2, -1, -2, -1, 2,-1, -2, -1, 2, -1, -2, -1, 2, -1, -2, -1, 2, -1, -2, -1, 2, -1, -2, -1, 2, -1, -2, -1, 2,1, -2, 1, 2, 1, -2, 1, 2, 1, -2, 1, 2, 1, -2, 1, 2, 1, -2, 1, 2}, // 더미 방향값
        5,10,10, // 체력
        "basic", // 타입

        // leftArm - hit / nonHit (2중 벡터로 변경)
        {
        // 프레임 0
        {
            { -5, 0 },{ -6, 0 },{ -7, 0 },
            { -5, 1 },{ -6, 1 },{ -7, 1 },{ -8, 1 },
            { -8, 2 },{ -9, 2 },
            { -9, 3 },{ -10, 3 }
        },
    // 프레임 1 (새로 추가한 애니메이션)
    {
        { -5, 0 },{ -6, 0 },{ -7, 0 },
        { -5, 1 } ,{ -6, 1 },{ -7, 1 },{ -8, 1 },
        { -7, 2 },{ -8, 2 },
        { -7, 3 },{ -8, 3 },
        { -7, 4 },{ -8, 4 }
    },
    {
        { -5, 0 },{ -6, 0 },
        { -5, 1 } ,{ -6, 1 },{ -7, 1 },
        { -6, 2 },{ -7, 2 },
        { -5, 3 },{ -6, 3 },
        { -4, 4 },{ -5, 4 },
        { -3, 5 },{ -4, 5 }
    }
},
// rightArm_nonHit는 그대로 유지
{
    {
        { -9, 4 }, { -10, 4 },{ -11, 4 },
        { -8, 5 }, { -12, 5 },
        { -8, 6 }, { -9, 6 }, { -10, 6 }, { -11, 6 }, { -12, 6 }
    },
    {
        { -7, 5 }, { -8, 5 },{ -9, 5 },
        { -6, 6 }, { -10, 6 },
        { -6, 7 }, { -7, 7 }, { -8, 7 }, { -9, 7 }, { -10, 7 }
    },

    {
        { -2, 6 }, { -3, 6 },{ -4, 6 },
        { -1, 7 }, { -5, 7 },
        { -1, 8 }, { -2, 8 }, { -3, 8 }, { -4, 8 }, { -9, 8 }
    }
},

    // rightArm - hit / nonHit (2중 벡터로 프레임 2개로 수정됨)
 {
     // 프레임 0
     {
         { 5, 0 },{ 6, 0 },{ 7, 0 },
         { 5, 1 },{ 6, 1 },{ 7, 1 },{ 8, 1 },
         { 8, 2 },{ 9, 2 },
         { 9, 3 },{ 10, 3 }
     },
    // 프레임 1 (새로 추가한 애니메이션)
    {
        { 5, 0 },{ 6, 0 },{ 7, 0 },
        { 5, 1 } ,{ 6, 1 },{ 7, 1 },{ 8, 1 },
        { 7, 2 },{ 8, 2 },
        { 7, 3 },{ 8, 3 },
        { 7, 4 },{ 8, 4 }
    },
    {
        { 5, 0 },{ 6, 0 },
        { 5, 1 } ,{ 6, 1 },{ 7, 1 },
        { 6, 2 },{ 7, 2 },
        { 5, 3 },{ 6, 3 },
        { 4, 4 },{ 5, 4 },
        { 3, 5 },{ 4, 5 }
    }
},
// rightArm_nonHit는 그대로 유지
{
    {
        { 9, 4 }, { 10, 4 },{ 11, 4 },
        { 8, 5 }, { 12, 5 },
        { 8, 6 }, { 9, 6 }, { 10, 6 }, { 11, 6 }, { 12, 6 }
    },
    {
        { 7, 5 }, { 8, 5 },{ 9, 5 },
        { 6, 6 }, { 10, 6 },
        { 6, 7 }, { 7, 7 }, { 8, 7 }, { 9, 7 }, { 10, 7 }
    },
    {
        { 2, 6 }, { 3, 6 },{ 4, 6 },
        { 1, 7 }, { 5, 7 },
        { 1, 8 }, { 2, 8 }, { 3, 8 }, { 4, 8 }, { 9, 8 }
    }
},


    
    {// shell
        {
            { 0, -2 },{ 1, -2 },{ 2, -2 },{ 3, -2 },{ -1, -2 },{ -2, -2 },{ -3, -2 },
            { 4, -1 },{ -4, -1 },{ 4, 0 },{ -4, 0 },{ 4, 1 },{ -4, 1 },
            { 3, 2 },{ -3, 2 },
            { 0, 3 },{ -1, 3 },{ -2, 3 },{ 1, 3 },{ 2, 3 }
        }
    },

    // body
    {
        {
            { 0, 0 },{ 0, 1 },{ 1, 0 },{ -1, 0 },{ 0, -1 }
        },
        {
            { 0, 0 },{ 1, 1 },{ 1, -1 },{ -1, 1 },{ -1, -1 }
        }
    }
}
};
