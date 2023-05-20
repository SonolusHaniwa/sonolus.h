class ArchetypeLifePointer: public Pointer<ArchetypeLifeId> {
    public:

    FuncNode perfectLifeIncrement = get(0);
    FuncNode greatLifeIncrement = get(1);
    FuncNode goodLifeIncrement = get(2);
    FuncNode missLifeIncrement = get(3);

    ArchetypeLifePointer() {
        this->offset = 0;
        this->size = 4;
    }

    ArchetypeLifePointer(FuncNode offset) {
        this->offset = offset;
        this->size = 4;
        perfectLifeIncrement = get(0);
        greatLifeIncrement = get(1);
        goodLifeIncrement = get(2);
        missLifeIncrement = get(3);
    }
};

PointerArray<ArchetypeLifePointer, 4> ArchetypeLife;