import subprocess
process=subprocess.Popen('sudo echo "Hi dude, how can I help you?" | festival --tts',shell=True,stdout=subprocess.PIPE)
process.wait()
print(process.returncode)
