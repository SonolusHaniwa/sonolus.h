class EntityInfoPointer: public Pointer<EntityInfoId> {
    public:

    FuncNode index = get(0);
    FuncNode archetype = get(1);
    FuncNode state = get(2);

    EntityInfoPointer() {
        this->offset = 0;
        this->size = 3;
    }

    EntityInfoPointer(FuncNode offset) {
        this->offset = offset;
        this->size = 3;
        index = get(0);
        archetype = get(1);
        state = get(2);
    }
};

PointerArray<EntityInfoPointer, 3> EntityInfo;