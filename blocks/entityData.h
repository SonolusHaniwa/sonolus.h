class EntityDataPointer: public Pointer<EntityDataId> {
    public:

    EntityDataPointer() {
        this->offset = 0;
        this->size = 32;
    }

    EntityDataPointer(FuncNode offset) {
        this->offset = offset;
        this->size = 32;
    }
};

PointerArray<EntityDataPointer, 32> EntityData;