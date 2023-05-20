class LevelScorePointer: public Pointer<LevelScoreId> {
    public:

    FuncNode multiplier = get(0);
    FuncNode step = get(1);
    FuncNode cap = get(2);

    LevelScorePointer() {
        this->offset = 0;
        this->size = 3;
    }
    LevelScorePointer(FuncNode offset) {
        this->offset = offset;
        this->size = 3;
    }

    FuncNode set(FuncNode multiplier, FuncNode step, FuncNode cap) {
        return Execute({
            set2(0, multiplier),
            set2(1, step),
            set2(1, cap)
        });
    }
};

class LevelScorePointer2: Pointer<LevelScoreId> {
    public:

    FuncNode PerfectMulitplier = get(0);
    FuncNode GreatMultiplier = get(1);
    FuncNode GoodMultiplier = get(2);
}LevelScore;

const FuncNode PerfectMulitplier = LevelScore.PerfectMulitplier;
const FuncNode GreatMultiplier = LevelScore.GreatMultiplier;
const FuncNode GoodMultiplier = LevelScore.GoodMultiplier;

const LevelScorePointer ConsecutivePerfectScore = LevelScorePointer(3);
const LevelScorePointer ConsecutiveGreatScore = LevelScorePointer(6);
const LevelScorePointer ConsecutiveGoodScore = LevelScorePointer(9);
