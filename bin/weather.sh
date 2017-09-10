#!/bin/sh

# Retrieve weather information from BOM website
wget -q -O- http://www.bom.gov.au/nsw/forecasts/sydney.shtml | egrep \"summary\" | head -3 | sed s/"^.*\"summary\">"// | sed s/"\.<\/dd>"//
#wget -q -O- http://www.bom.gov.au/nsw/forecasts/sydney.shtml | egrep \"summary\"

#echo "cloudy"
