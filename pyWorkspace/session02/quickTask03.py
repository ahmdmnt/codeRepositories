#!/usr/bin/python3

## QuickTask: 3.0
### Code to find automatically bitcoin rate
import requests
 
bitcoinResult = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
bitcoinDict = dict(bitcoinResult.json())["bpi"]

print(f"{bitcoinDict["GBP"]["description"]}: \nBitcoin: {bitcoinDict["GBP"]["rate"]} GBP\n")
print(f"{bitcoinDict["EUR"]["description"]}: \nBitcoin: {bitcoinDict["EUR"]["rate"]} EUR\n")
print(f"{bitcoinDict["USD"]["description"]}: \nBitcoin: {bitcoinDict["USD"]["rate"]} USD\n")
##########################################################