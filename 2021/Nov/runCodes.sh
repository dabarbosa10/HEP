inputDir=$1
for file in `cat mutau.txt`; do
  echo $file
  cp dumpBinContent_COPY.C dumpBinContent.C 
  sed -i .bak "s:DIRECTORY:$inputDir:g" dumpBinContent.C
  sed -i .bak "s:FILE:$file:g" dumpBinContent.C 
  root -l -b -q dumpBinContent.C
done
