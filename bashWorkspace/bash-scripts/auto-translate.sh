#! /bin/bash

## SCRIPT DESCRIPTION
# Translate the Copied a word using google translate
############################################################

MY_WORD=$(xclip -o sel)
TRANSLATE_URL="https://translate.google.com/?sl=en&tl=ar&text=$MY_WORD&op=translate"

firefox $TRANSLATE_URL