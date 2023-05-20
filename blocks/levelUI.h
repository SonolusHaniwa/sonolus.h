class LevelUIPointer: public Pointer<LevelUIId> {
    public:

    FuncNode anchorX = get(0);
    FuncNode anchorY = get(1);
    FuncNode pivotX = get(2);
    FuncNode pivotY = get(3);
    FuncNode width = get(4);
    FuncNode height = get(5);
    FuncNode rotation = get(6);
    FuncNode alpha = get(7);
    FuncNode horizontalAlign = get(8);
    FuncNode Background = get(9);

    LevelUIPointer() {
        this->offset = 0;
        this->size = 10;
    }  
    LevelUIPointer(FuncNode offset) {
        this->offset = offset;
        this->size = 10;
        anchorX = get(0);
        anchorY = get(1);
        pivotX = get(2);
        pivotY = get(3);
        width = get(4);
        height = get(5);
        rotation = get(6);
        alpha = get(7);
        horizontalAlign = get(8);
        Background = get(9);
    }

    FuncNode set(
        FuncNode anchorX, 
        FuncNode anchorY, 
        FuncNode pivotX, 
        FuncNode pivotY, 
        FuncNode width, 
        FuncNode height, 
        FuncNode rotation, 
        FuncNode alpha, 
        FuncNode horizontalAlign, 
        FuncNode background
    ) {
        return Execute({
            set2(0, anchorX),
            set2(1, anchorY),
            set2(2, pivotX),
            set2(3, pivotY),
            set2(4, width),
            set2(5, height),
            set2(6, rotation),
            set2(7, alpha),
            set2(8, horizontalAlign),
            set2(9, background)
        });
    }
};

class LevelUIPointer2: Pointer<LevelUIId> {
    public:

}LevelUI;

const LevelUIPointer UIMenu = LevelUIPointer(0);
const LevelUIPointer UIJudgment = LevelUIPointer(10);
const LevelUIPointer UIComboValue = LevelUIPointer(20);
const LevelUIPointer UIComboText = LevelUIPointer(30);
const LevelUIPointer UIPrimaryMetricBar = LevelUIPointer(40);
const LevelUIPointer UIPrimaryMetricValue = LevelUIPointer(50);
const LevelUIPointer UISecondaryMetricBar = LevelUIPointer(60);
const LevelUIPointer UISecondaryMetricValue = LevelUIPointer(70);