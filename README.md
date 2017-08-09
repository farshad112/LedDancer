# LedDancer
Led animation Program for PIC18F452 micro controller using Proteus and CCS compiler

## currently supported modes:
1. Auto mode: Runs all the animation modes automatically one by one.
2. Manual mode: Selects animation based on user input.

## Enabling Auto mode:
To enable auto animation mode please uncomment "#define ENABLE_AUTO_LED_ANIMATION" line in LedDancer.c file

## Enabling Manual Mode:
To enable auto animation mode please comment "#define ENABLE_AUTO_LED_ANIMATION" line in LedDancer.c file

## Currently supported animations:
1. BLINK_ALL_LED_AT_A_TIME
2. MOVE_TWO_LED_LEFT_TO_RIGHT
3. MOVE_ONE_LED_LEFT_TO_RIGHT
4. MOVE_TWO_LED_RIGHT_TO_LEFT
5. MOVE_ONE_LED_RIGHT_TO_LEFT
6. BLINK_ONLY_EVEN_LED
7. BLINK_ONLY_ODD_LED
8. TOGGLE_EVEN_AND_ODD_LED
