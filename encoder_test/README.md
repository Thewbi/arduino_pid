# Introduction

The purpose of this test is to get to know the encoder and it's output in isolation from all other features of a PID control system.
No PID controller is involved. After the test, it is validated that:

- the power supply works
- the motor works
- which wire on the motor is used for which purpose
- the wiring is correct
- the motor encoder works
- the arduino works
- the signals that the encoder outputs can be converted to meaningful information on the arduino.

This first test will use a DC power supply to drive the motor at constant speed based on the voltage supplied.
It will read signals from the DC motor's encoder and process the encoder signals using the Arduino.

This encoder test lays the groundwork for a closed loop system used in later steps.

## Motor and wiring

The motor used is the JGB-520.
It is a 12V DC motor that goes up to 1000 RPM according to the label on the housing.

eBay: https://www.ebay.de/itm/166471920023?_trkparms=amclksrc%3DITM%26aid%3D1110006%26algo%3DHOMESPLICE.SIM%26ao%3D1%26asc%3D265241%2C265017%26meid%3D386c93f198de490f84fe996920bf2f1d%26pid%3D101195%26rk%3D4%26rkt%3D12%26sd%3D404335257982%26itm%3D166471920023%26pmt%3D1%26noa%3D0%26pg%3D4429486%26algv%3DSimplAMLv11WebTrimmedV3MskuWithLambda85KnnRecallV1V2V4ItemNrtInQueryAndCassiniVisualRankerAndBertRecallWithVMEV3EmbeddedAuctionsCPCAutoWithCassiniEmbRecallManual%26brand%3DMarkenlos&_trksid=p4429486.c101195.m1851&itmprp=cksum%3A166471920023386c93f198de490f84fe996920bf2f1d%7Cenc%3AAQAJAAABgP9d%252BMZSXlztIfYFu3kI%252B7ft0VcQix7rTrUVdiJwc2upzwLfM%252B2UEqu0ZqdXqu2qWe6up6s9MSEY%252BWikIwEh4xLkizL%252BG%252Fyhg6cdW4xfkbb75erVQBYYISNxGN1au%252BE0eJ778JYYSAyLJRupNiZky3B2UHpMsaEp7JRgW9fuueOszPlG9eCPE4mSzJx4EejjZE0v1xx3s4HgKujjhEB3s6k8JsGl%252BIkmScqtVDwEA6NKqeEiEHJGeSRFsIRjdBoTwlTohv6S1NFGSz1KfL6WKeIIWOcgy68M2lIuQ%252FI3RRGE9WH%252FRlx6NtSAYkN%252BEEccpeN7WuV3CE05hEc77wP4eo0LcH9ZOay0kCwwx%252BhtbebClTRbP22dAUIsDyUYDMGnwsqByAoZu4qowmO%252FqciiHPC3Z4w5l51BpuyDiv6RkERoXIavULsfEISTtJUe4ECPyxJYsU1Z9bVwCYKSrhe9HwWl1CQf%252BWEklHBgyeZgNRcTh8SfxiafN4D3AtGK9cpwTw%253D%253D%7Campid%3APL_CLK%7Cclp%3A4429486&itmmeta=01HXTP5NG5JB5WBVJWKC0DA99N

![JGB-520](images\s-l1600.jpg)