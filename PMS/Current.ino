double getCurrent(int no)
{
  double adc_current = ADS1.toVoltage(val1[no]);
  double current;
  //noise reading without load is approximately 0.04 v
  if(adc_current >= 2.50 && adc_current <= 2.54)
  {
    adc_current = 2.50;
    //offset = 0.3
    current = ((2-(4.5-adc_current))/0.1);  
  }
  else
  {
    current = ((2-(4.5-ADS1.toVoltage(val1[no])))/0.1)-0.3;
  }

  return current-0.5;
}
