#include<jsoncpp/json/json.h>
#include<openssl/ssl.h>

#include"modules/modules.h"
#include"items/EngineConfiguration.h"
#include"items/EngineData.h"
#include"items/FuncNode.h"
#include"functions/functions.h"
#ifndef DISABLE_REDEFINE
#include"functions/redefine.h"
#endif
#ifndef DISABLE_JSPREFER
typedef FuncNode var;
typedef FuncNode let;
#endif

void build(EngineConfiguration configuration, EngineData data, buffer& configurationBuffer, buffer& dataBuffer) {
    cerr << json_encode(configuration.toJsonObject()) << endl;
    configurationBuffer = compress_gzip(json_encode(configuration.toJsonObject()), 9);
}