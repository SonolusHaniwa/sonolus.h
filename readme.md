# Sonolus.h

C++ based Developer Toolkit for Sonolus.

## Links

- [Sonolus Website](https://sonolus.com)
- [Sonolus Wiki](https://wiki.sonolus.com)
- [Sonolus.js Guide](https://wiki.sonolus.com/sonolus.js-guide)

Documents were avaliable in <https://docs.littleyang.com.cn/sonolus.h-en/>

## Usage

Use the following command to compile compiler:

```bash
g++ compiler/main.cpp -ocompiler/main -O3
```

Then, simply create a new file, import `bits/stdc++.h` first and then import the `sonolus.h` header.

## Compile Usage

```bash
mkdir .sonolus && ./compiler/main main.cpp .sonolus
g++ .sonolus/main.cpp -omain -g -w -fpermissive -ljsoncpp -lz -lpng -lzip -Dplay
```

## API

### Basic

- `SonolusApi`: The type of return value of a Sonolus function.
- `var`: Base variable type.

Structures:

- `Array`: Array structure in Sonolus.
- `Collection`: Collection(Vector) structure in Sonolus.
- `Dictionary`: Dictionary(Map) structure in Sonolus.
- `Mat`: Matrix structure in Sonolus.
- `Vec`: Vector2D structure in Sonolus.
- `Range`: Range structure in Sonolus.
- `Quad`: Quadratic structure in Sonolus.

### Literals

- `Text`: a list of texts which can be translated automatically in Sonolus.
- `Icon`: Useless.
- `EngineArchetypeName`: A list of archetype names.
- `EngineArchetypeDataName`: A list of data names of a archetype.
- `EngineConfigurationMetric`: A list of metric names.
- `EngineConfigurationAnimationTweenEase`: A list of animation ease functions.
- `EngineConfigurationJudgmentErrorStyle`: A list of judgment error styles.
- `EngineConfigurationJudgmentErrorPlacement`: A list of judgment error placements.
- `HorizontalAlign`: Horizontail align. See <https://wiki.sonolus.com/engine-specs/play-blocks/runtime-ui#values>
- `InstructionIconName`: A list of instruction icons.
- `CanvasScroll`: Canvas direction(Preview mode only).
- `PrintFormat`: Print format(Preview mode only).
- `PrintColor`: Print color(Preview mode only).

### Engine API

Define functions:

- `defineImport`: Define imported data of current archetype.
- `defineImportDetailed`: Define imported data of current archetype.
- `defineExport`: Define exported data of current archtype(Play mode only).
- `defineExportDetailed`: Define exported data of current archtype(Play mode only).
- `defineTutorialPreprocess`: Define preprocess function(Tutorial mode only).
- `defineTutorialSegment`: Define segment function(Tutorial mode only).
- `defineTutorialSegmentsGroup`: Represents the end of current segments group(Tutorial mode only).
- `defineTurorialStatic`: Define static function(Tutorial mode only).
- `defineUpdateSpawn`: Define `updateSpawn` function(Watch mode only).
- `defineBucket`: Define a bucket.
- `defineInstructionText`: Define a instruction text.
- `defineInstructionIcon`: Define a instruction icon.
- `getAid`: Get archetype id by **class name**.

Configuration functions:

- `SliderOption`: Define a slider option.
- `ToggleOption`: Define a toggle option.
- `SelectOption`: Define a select option.
- `UI.SetScope`: Set scope.
- `UI.SetMetric`: Set metric UI.
- `UI.SetMenu`: Set menu UI.
- `UI.SetJudgment`: Set judgment UI.
- `UI.SetCombo`: Set combo UI.
- `UI.SetProgress`: Set progress UI.
- `UI.SetTutorial`: Set tutorial UI.

Build functions:

- `BuildConfiguration`: Build engine configuration.
- `BuildPlayData`: Build engine play data(Play mode only).
- `BuildTutorialData`: Build engine play data(Tutorial mode only).
- `BuildPreviewData`: Build engine play data(Preview mode only).
- `BuildWatchData`: Build engine play data(Watch mode only).

### Skin API

- `defineSkinSprite`: Define a skin sprite.
- `PackSkin`: Pack skin texture and skin data.

### Effect API

- `defineEffectClip`: Define a effect clip.
- `PackEffect`: Pack effect audio and effect data.

### Particle API

- `defineParticleEffect`: Define a particle effect.

### LevelData API

Define functions:

- `defineArchetypeName`: Define archetype name of current entity.
- `defineLevelDataValue`: Define a value variable.
- `defineLevelDataValueDetailed`: Define a value variable.
- `defineLevelDataRef`: Define a ref variable.
- `defineLevelDataRefDetailed`: Define a ref variable.

LevelRawData:

- `LevelRawData.bgmOffset`: BGMOffset of this level data.
- `LevelRawData.append`: Insert a entity into the end of this level data.
- `LevelRawData.get`: Get a entity from this level data.
- `LevelRawData.front`: Get the first entity from this level data.
- `LevelRawData.back`: Get the last entity from this level data.
- `LevelRawData.size`: Get the size of this level data.
- `LevelRawData.toJsonObject`: Convert this level data to json object.

Other functions:

- `Transform`: Transform a entity from one archetype into another archetype.

### Others

`jsoncpp` library:

- `json_encode`: Encode a json object to a string.
- `json_pretty_encode`: Encode a json object to a string.
- `json_decode`: Decode a string to a json object.

`zlib` library:

- `compress_gzip`: Compress a string to a gzip string.
- `decompress_gzip`: Decompress a gzip string to a string.

## Macros

- `DISABLE_INTERPRETER`: Disable interpreter features temporarily.
- `DISABLE_PACK_SKIN`: Disable packing skin feature.
- `DISABLE_PACK_EFFECT`: Disable packing effect feature.
- `play`: Switch compile mode to play mode.
- `tutorial`: Switch compile mode to tutorial mode.
- `preview`: Switch compile mode to preview mode.
- `watch`: Switch compile mode to watch mode.
