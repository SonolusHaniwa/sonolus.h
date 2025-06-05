#ifndef Blocks_H
#define Blocks_H

template<typename T>
class BlocksArray {
    public:

    FuncNode arraySize = 0;
    Constructor BlocksArray(){}
    Constructor BlocksArray(FuncNode arraySize): arraySize(arraySize){}

    T operator [] (FuncNode index) {
        return T(index * arraySize);
    }
};

template<int allocatorId> 
class VariablesArray {
    public:

    FuncNode offset = 0;
    FuncNode siz = 0;
    Constructor VariablesArray(){}
    Constructor VariablesArray(FuncNode offset, FuncNode siz): offset(offset), siz(siz){}

    Variable *tmp = NULL;
    Variable& operator [] (FuncNode index) {
        if (tmp != NULL) delete tmp;
        tmp = new Variable(allocatorId, offset + index);
        return *tmp;
    }
};

#endif