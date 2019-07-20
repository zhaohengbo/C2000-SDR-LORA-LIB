# C2000_SDR_LORA_LIB

 This is a LORA transreceiver based on SDR.
 
 The hardware and software are similar to C2000_SDR(https://github.com/zhaohengbo/C2000-SDR)
 
 Be aware of that the modulation type I used is not exactly lora.
 
 I do a little bit change to the downchirp time so that the system seems to be more harmonious.
 
 By the way, the link laywer was a little bit different from original LORA.
 
 The PHY struct looks like:

	(Preamble(5 upchirp, 3 downchirp) ->(                                   PHY Payload                                 ))

					    (Type -> Source Address -> Destination Address -> Data Length -> Data(32byte max))
 
 The lora mod/demod functions are provide by library recently!
 
 **The performance of the mod/demod algorthm was found to be even better than that from semtech itself(And of course, than other SDR-Lib) while maintaining a lower algorithm complexity.**
 
 **Therefore I was asked to write a patent or a paper before open-source these functions.**
 
 The recent version are just for test and fun(**No shaping filter was introduced!!!**), there is still a long way to go before commercial use.
 
 Thanks for all of your support, maybe we can go on this project 3 years later in college.
