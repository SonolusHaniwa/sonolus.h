class LevelLifePointer: public Pointer<LevelLifeId> {
    public:

    FuncNode increment = get(0);
    FuncNode step = get(1);

    LevelLifePointer(){
        this->offset = 0;
        this->size = 2;
    }
    LevelLifePointer(FuncNode offset) {
        this->offset = offset;
        this->size = 2;
        increment = get(0);
        step = get(1);
    }
};

const LevelLifePointer ConsecutivePerfectLife = LevelLifePointer(0);
const LevelLifePointer ConsecutiveGreatLife = LevelLifePointer(2);
const LevelLifePointer ConsecutiveGoodLife = LevelLifePointer(4);