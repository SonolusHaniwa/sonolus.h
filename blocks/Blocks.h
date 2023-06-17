const int LevelMemoryId = 2000;
const int LevelDataId = 2002;
// const int LevelOptionId = 2;
// const int LevelTransformId = 3;
// const int LevelBackgroundId = 4;
// const int LevelUIId = 5;
const int LevelBucketId = 2003;
const int LevelScoreId = 2004;
const int LevelLifeId = 2005;
// const int LevelUIConfigurationId = 9;
const int EntityInfoArrayId = 4103;
const int EntityDataArrayId = 4101;
const int EntitySharedMemoryArrayId = 4102;
const int EntityInfoId = 4003;
const int EntityMemoryId = 4000;
const int EntityDataId = 4001;
const int EntityInputId = 4005;
const int EntitySharedMemoryId = 4002;
const int ArchetypeLifeId = 5000;
const int EngineRomId = 3000;
const int TemporaryMemoryId = 10000;
// const int TemporaryTouchDataId = 101;
const int EntityDespawnId = 4004;
const int RuntimeEnvironmentId = 1000;
const int RuntimeUpdateId = 1001;
const int RuntimeTouchArrayId = 1002;
const int RuntimeSkinTransformId = 1003;
const int RuntimeParticleTransformId = 1004;
const int RuntimeBackgroundId = 1005;
const int RuntimeUIId = 1006;
const int RuntimeUIConfigurationId = 1007;

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

// #include"archetypeLife.h"
// #include"engineRom.h"
// #include"entityData.h"
// #include"entityInfo.h"
// #include"entityInput.h"
// #include"entityMemory.h"
// #include"entitySharedMemory.h"
// #include"levelBackground.h"
// #include"levelBucket.h"
// #include"levelData.h"
// #include"levelLife.h"
// #include"levelMemory.h"
// #include"levelOption.h"
// #include"levelScore.h"
// #include"levelTransform.h"
// #include"levelUI.h"
// #include"levelUIConfiguration.h"
// #include"temporaryMemory.h"
// #include"temporaryTouchData.h"