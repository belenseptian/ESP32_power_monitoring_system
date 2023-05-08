double getVoltage(int no)
{
  double voltage = ADS0.toVoltage(val0[no])/0.2;
  if(voltage < 0)
  {
    voltage = 0;
  }
  else
  {
    voltage = ADS0.toVoltage(val0[no])/0.2;
  }
  //no ranges from 0-2
  //0.2 is a ratio of voltage divider
  return voltage;
}
