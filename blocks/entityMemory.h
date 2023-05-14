class EntityMemoryPointer: public Pointer<EntityMemoryId> {
    public:

    EntityMemoryPointer() {
        this->offset = 0;
        this->size = 64;
    }
}EntityMemory;