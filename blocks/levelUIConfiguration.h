class LevelUIConfigurationPointer: public Pointer<LevelUIConfigurationId> {
    public:

    FuncNode scale = get(0);
    FuncNode alpha = get(1);

    LevelUIConfigurationPointer() {
        this->offset = 0;
        this->size = 2;
    }  
    LevelUIConfigurationPointer(FuncNode offset) {
        this->offset = offset;
        this->size = 2;
        scale = get(0);
        alpha = get(1);
    }
};

class LevelUIConfigurationPointer2: Pointer<LevelUIConfigurationId> {
    public:

}LevelUIConfiguration;

const LevelUIConfigurationPointer UIMenuConfiguration = LevelUIConfigurationPointer(0);
const LevelUIConfigurationPointer UIJudgmentConfiguration = LevelUIConfigurationPointer(2);
const LevelUIConfigurationPointer UIComboConfiguration = LevelUIConfigurationPointer(4);
const LevelUIConfigurationPointer UIPrimaryMetricConfiguration = LevelUIConfigurationPointer(6);
const LevelUIConfigurationPointer UISecondaryMetricConfiguration = LevelUIConfigurationPointer(8);

