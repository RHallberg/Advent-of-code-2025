
NR == 1 {
  for(i = 1; i <= NF; i++){
    operands[i] = $i
  }
}

{
  for(i = 1; i <= NF; i++){

    if(operands[i] == "*"){
      v = NR == 2 ? 1 : res[i]
      res[i] = v * $i
    }
    else{
      res[i]+= $i
    }
  }
}

END{
  for(i = 1; i <= NF; i++){
    sum+= res[i]
  }
  print sum
}
