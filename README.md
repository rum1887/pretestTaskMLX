# Pretest Task MLX

### System information 

```bash
Hardware: Apple M1 Arm64, 8GB RAM
Operating System: macOS Sonoma 14.3
Kernel Version: Darwin 23.3.0
```
### Framework execution

1. Built and installed C++ API from source following the [MLX](https://ml-explore.github.io/mlx/build/html/install.html) documentation. Also installed the mlx binaries in Python from PyPI using</br>
   ```python
   pip install mlx
   ```
   <img width="1440" alt="mlxBuildLogs1" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/c7160026-12f5-433d-a8a0-61768c852f8d"></br>
   ![mlxBuildLogs2](https://github.com/rum1887/pretestTaskMLX/assets/57267583/33800c6d-71cb-48ce-af6a-570699e969d6)
2. Regression Example in MLX {C++ APIs}.</br></br> Modified logistic and linear regression files in the [mlx repository]([https://github.com/ml-explore/mlx/tree/main/examples/cpp](https://github.com/rum1887/mlx/tree/cppexamples)) ( Calculated elapsed time).

   Steps to reproduce:

   Clone my [fork](https://github.com/rum1887/mlx/tree/cppexamples) and re-build the project or download the modified files ([modified_linear_regression.cpp](https://github.com/rum1887/pretestTaskMLX/blob/main/modified_linear_regression.cpp), [modified_logistic_regression](https://github.com/rum1887/pretestTaskMLX/blob/main/modified_logistic_regression.cpp)) and the [CMakeLists.txt](https://github.com/rum1887/pretestTaskMLX/blob/main/CMakeLists.txt) into the examples folder.
   Navigate to the examples folder.
   
   ```bash
   cd mlx/examples/cpp
   ```
   Rebuild the project in the root directory mlx using
   ```bash
   mkdir -p build && cd build
   cmake .. && make -j
   ```

   Navigate to the build directory:
   ```bash
   cd build/examples/cpp
   ```
   And execute the executables in the dir:</br></br>
   ```bash
   ./tutorial
   ```
   <img width="1440" alt="modified_regression" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/34287bd5-9628-4d1f-be35-c0f485146573">
   
3. Speech recogntion using whisper in MLX {Python APIs}. </br></br>
   Modified the following [example](https://github.com/ml-explore/mlx-examples/tree/main/whisper) to transcribe a 3.2Mb, 0.18-second audio file ([harvard.wav](https://www.kaggle.com/datasets/pavanelisetty/sample-audio-files-for-speech-recognition)) using the Whisper model by OpenAI with the MLX backend in 0.65 seconds.</br></br>
   Steps to reproduce:</br> Download [transcribeScript.py](https://github.com/rum1887/pretestTaskMLX/blob/main/transcribeScript.py) and harvard.wav into the whisper directory created from following the example above.</br></br>
   To run the script:</br>
   ```python
   python3 transcribeScript.py
   ```  
   <img width="1139" alt="MLXWhisperSpeechRecognition" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/db57d4ae-6322-4a81-b6a1-97457aed7497">
   
---
### Section(2)
1. Built WasmEdge with llama.cpp plugin by following this [guide](https://wasmedge.org/docs/contribute/source/plugin/wasi_nn/#build-wasmedge-with-wasi-nn-llamacpp-backend).

   ![wasmedge](https://github.com/rum1887/pretestTaskMLX/assets/57267583/38f0f2f9-8977-41f1-8099-94e84edc2016)
   
2. Execution(1) llama.cpp  </br></br>
   Followed this [example](https://github.com/second-state/WasmEdge-WASINN-examples/tree/master/wasmedge-ggml) to run "llama2 7b chat model in GGUF format" in WasmEdge</br></br><img width="1440" alt="llama" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/5cf10e24-8260-4458-bb1b-a51d6b606086">
   
3. Execution(2) API Server</br></br>
   Chose "Mistral-7B-Instruct-v0.1" to run and created an OpenAI compatible API server for the model following this [guide](https://github.com/second-state/LlamaEdge/tree/main/api-server). Web UI:
   
   <img width="1440" alt="Screenshot 2024-02-17 at 6 03 54 PM" src="https://github.com/rum1887/pretestTaskMLX/assets/57267583/ce1a5ff1-3ca3-49a4-a5b3-5255b9474227">
---
### Troubleshooting
1. If you updated your macOS and Xcode to Sonoma, yet the SDKs used during the build are of an older version, remove the CMake cache in the build dir and rebuild the project.
   ```bash
   rm CMakeCache.txt
   ``` 
