class EntitySharedMemoryPointer: public Pointer<EntitySharedMemoryId> {
    public:

    EntitySharedMemoryPointer() {
        this->offset = 0;
        this->size = 32;
    }

    EntitySharedMemoryPointer(FuncNode offset) {
        this->offset = offset;
        this->size = 32;
    }
};

PointerArray<EntitySharedMemoryPointer, 32> EntitySharedMemory;