class EntityInputPointer: public Pointer<EntityInputId> {
    public:

    EntityInputPointer() {
        this->offset = 0;
        this->size = 4;
    }
}EntityInput;

const FuncNode InputJudgement = EntityInput.get(0);
const FuncNode InputAccuracy = EntityInput.get(1);
const FuncNode InputBucket = EntityInput.get(2);
const FuncNode InputBucketValue = EntityInput.get(3);