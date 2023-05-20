int readAccess[] = {
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b00000100,
};

int writeAccess[] = {
    0b10001100,
    0b10000000,
    0b10000000,
    0b10001100,
    0b10001100,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b10000000,
    0b10001100,
    0b00000000,
    0b11111111,
    0b10000000,
    0b11111111,
    0b10001100,
    0b10000000,
    0b00000000,
    0b11111111,
    0b00000000
};

const int LevelMemoryId = 0;
const int LevelDataId = 1;
const int LevelOptionId = 2;
const int LevelTransformId = 3;
const int LevelBackgroundId = 4;
const int LevelUIId = 5;
const int LevelBucketId = 6;
const int LevelScoreId = 7;
const int LevelLifeId = 8;
const int LevelUIConfigurationId = 9;
const int EntityInfoArrayId = 10;
const int EntityDataArrayId = 11;
const int EntitySharedMemoryArrayId = 12;
const int EntityInfoId = 20;
const int EntityMemoryId = 21;
const int EntityDataId = 22;
const int EntityInputId = 23;
const int EntitySharedMemoryId = 24;
const int ArchetypeLifeId = 30;
const int EngineRomId = 50;
const int TemporaryMemoryId = 100;
const int TemporaryTouchDataId = 101;

template<int identifierId>
class Pointer {
    public:
    
    FuncNode offset = 0;
    int size = -1;

    FuncNode get(FuncNode i) {
        if (size != -1 && i.isValue == true &&
            (i.value >= size || i.value < 0)) throwWarning("");
        return Get(identifierId, Add({i, offset}));
    }

    FuncNode set(FuncNode i, FuncNode value) {
        if (size != -1 && i.isValue == true &&
            (i.value >= size || i.value < 0)) throwWarning("");
        return Set(identifierId, Add({i, offset}), value);
    }

    FuncNode set2(FuncNode i, FuncNode value) {
        return set(i, value);
    }
};

template<typename T, int blockSize>
class PointerArray {
    public:

    T operator [] (int offset) {return T(Multiply({offset, blockSize}));}
    T operator [] (FuncNode offset) {return T(Multiply({offset, blockSize}));};
};

#include"archetypeLife.h"
#include"engineRom.h"
#include"entityData.h"
#include"entityInfo.h"
#include"entityInput.h"
#include"entityMemory.h"
#include"entitySharedMemory.h"
#include"levelBackground.h"
#include"levelBucket.h"
#include"levelData.h"
#include"levelLife.h"
#include"levelMemory.h"
#include"levelOption.h"
#include"levelScore.h"
#include"levelTransform.h"
#include"levelUI.h"
#include"levelUIConfiguration.h"
#include"temporaryMemory.h"
#include"temporaryTouchData.h"