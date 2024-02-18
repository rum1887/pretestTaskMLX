# pretestTaskMLX
1. Built and installed C++ API from source following the [MLX](https://ml-explore.github.io/mlx/build/html/install.html) documentation. Also installed the mlx binaries in Python from PyPI using ```pip install mlx```</br></br>
   <img width="1440" alt="mlxBuildLogs1" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/c7160026-12f5-433d-a8a0-61768c852f8d">
   ![mlxBuildLogs2](https://github.com/rum1887/pretestTaskMLX/assets/57267583/33800c6d-71cb-48ce-af6a-570699e969d6)
2. Logistic and linear regression using the MLX C++ APIs. </br></br><img width="1440" alt="Screenshot 2024-02-17 at 4 47 10 PM" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/1f2c814b-4414-44c6-8825-06632b8f313e">
   
3. Speech recogntion using whisper in MLX Python APIs. </br></br>
   Modified the following [example](https://github.com/ml-explore/mlx-examples/tree/main/whisper) to transcribe a 3.2Mb, 0.18-second audio file ([harvard.wav](https://www.kaggle.com/datasets/pavanelisetty/sample-audio-files-for-speech-recognition)) using the Whisper model by OpenAI with the MLX backend in 0.65 seconds.
   
   <img width="1139" alt="MLXWhisperSpeechRecognition" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/db57d4ae-6322-4a81-b6a1-97457aed7497">

5. Building WasmEdge with llama.cpp plugin

   ![wasmedge](https://github.com/rum1887/pretestTaskMLX/assets/57267583/38f0f2f9-8977-41f1-8099-94e84edc2016)
   
6. llama.cpp Example </br></br>
   Modified this [example](https://github.com/second-state/WasmEdge-WASINN-examples/tree/master/wasmedge-ggml) to run "llama2 7b chat model in GGUF format" in WasmEdge

   
   <img width="1440" alt="llama cppWasmEdge" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/26d62fd2-e033-4946-b85f-bdffef5bb89c">
7. API Server Example</br></br><img width="1440" alt="Screenshot 2024-02-17 at 6 03 54 PM" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/ce1a5ff1-3ca3-49a4-a5b3-5255b9474227">

### Troubleshooting
1. If you updated your macOS and Xcode to Sonoma, yet the SDKs used during the build are of an older version, remove the CMake cache using ```rm CMakeCache.txt```.
