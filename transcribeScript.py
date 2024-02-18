import whisper
import time
speech_file="harvard.wav"
text = whisper.transcribe(speech_file)["text"]
time1=time.time()
result = whisper.transcribe(speech_file, path_or_hf_repo="mlx-community/whisper-tiny")
timefinal=time.time()-time1
print(result["text"])
print("Time taken: "+ str(timefinal)+"s")
#output = whisper.transcribe(speech_file, word_timestamps=True)
#print(output["segments"][0]["words"])
