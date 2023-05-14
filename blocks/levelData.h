class LevelDataPointer: public Pointer<LevelDataId> {
    public:

    LevelDataPointer() {
        this->offset = 0;
        this->size = 4096;
    }
}LevelData;

const FuncNode Time = LevelData.get(0);
const FuncNode DeltaTime = LevelData.get(1);
const FuncNode ScreenAspectRatio = LevelData.get(2);
const FuncNode AudioOffset = LevelData.get(3);
const FuncNode InputOffset = LevelData.get(4);
const FuncNode RenderScale = LevelData.get(5);
const FuncNode AntiAliasing = LevelData.get(6);