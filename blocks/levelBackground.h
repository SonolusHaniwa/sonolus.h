class LevelBackgroundPointer: public Pointer<LevelBackgroundId> {
    public:

    LevelBackgroundPointer() {
        this->offset = 0;
        this->size = 8;
    }
}LevelBackground;