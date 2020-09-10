# AutonomousGarden
Home automation for my personal garden. In progress . 

THE PROJECT

Components I used:

This DIY Kit for automatic watering from Amazon Japan (which had the best price for the amount of components): https://www.amazon.co.jp/gp/product/B07VNDZDCR/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1 - It has all the basics, soil humidity sensors, pumps, relay and hose. 
Rain detection module for Arduino. This can be used to detect water level, which is how I used it for. This is a very common component, but here is a link: https://www.amazon.co.jp/gp/product/B081VVYXZQ/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1
Arduino Uno R3 
A solar rechargeable power bank (this is a challenge to use, because the Arduino mayb not draw enough current to keep it on when in a waiting cycle). I used this: https://www.amazon.co.jp/gp/product/B08CXMPDTQ/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1
A soldering iron and cables. I recommend using a soldering tip that you don’t like to poke holes into the water container, because the plastic can ruin you soldering tip.
A big plastic container for water (plastic is easier to poke holes into, if you don’t have a power drill). 

If you decide to build this yourself using this information, please select the components according to your need. Like if you have a smaller garden you can have less pumps or even just one better blocking pump (those used in aquariums). 


THE CODE:

You will find the base code in my GitHub. 

You will notice that I do not use any power saving feature on the Arduino. This is because the Arduino doesn’t seem to draw enough current to keep the power bank awake, so the system was shutting off every time the pumps weren’t on. I fixed this by adding some fairy lights powered by the power bank, so that there is a constant current draw. So I had to avoid power saving... so weird right? But it does look very cute! 
