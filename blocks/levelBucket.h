class LevelBucketPointer: public Pointer<LevelBucketId> {
    public:

    FuncNode minPerfect = get(0);
    FuncNode maxPerfect = get(1);
    FuncNode minGreat = get(2);
    FuncNode maxGreat = get(3);
    FuncNode minGood = get(4);
    FuncNode maxGood = get(5);

    LevelBucketPointer() {
        this->offset = 0;
        this->size = 6;
    }

    LevelBucketPointer(FuncNode offset) {
        this->offset = offset;
        this->size = 6;
    }

    FuncNode setBucket(FuncNode minPerfect, FuncNode maxPerfect, FuncNode minGreat, FuncNode maxGreat, FuncNode minGood, FuncNode maxGood) {
        return Execute({
            set(0, minPerfect),
            set(1, maxPerfect),
            set(2, minGreat),
            set(3, maxGreat),
            set(4, minGood),
            set(5, maxGood)
        });
    }

    FuncNode setBucket(FuncNode maxPerfect, FuncNode maxGreat, FuncNode maxGood) {
        return Execute({
            set(0, Multiply({-1, maxPerfect})),
            set(1, maxPerfect),
            set(2, Multiply({-1, maxGreat})),
            set(3, maxGreat),
            set(4, Multiply({-1, maxGood})),
            set(5, maxGood)
        });
    }
};

PointerArray<LevelBucketPointer, 6> LevelBucket;