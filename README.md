# Trustless Random Generator (TRG)
TRG removes all necessary trust in random number generation. It is used to remove third parties and keep transparency.

![Imgur](https://i.imgur.com/egJUQjr.png)

# Use case
Imagine that Bob is organizing a drawing contest held in a limited timeframe that follows a specific theme. Note that Bob is also participating in the event. He says he will announce a "randomly generated" theme tonight from a public list of possible themes at 8pm which will mark the start of the event. How can you be certain that Bob won't pick the theme of his choice multiple hours before the start of the event and give himself a head start? TRG removes the "Organizer advantage" and the need of a third party to verify the integrity of the results. It ensures that the organizer randomly generates the data at the time he said he would.

# How does it work?
TRG uses the blockchain's immutability as a solution. The program fetches the most recent block hash that will be used as a seed for the random generation. Users can verify that the used seed was a valid hash at the moment the organizer said he would generate the data. Multiple blockchains are available such as BTC, ETH and LTC, offering different tradeoffs in possible risks.

# Verifying results
TRG allows you to verify the results for a specific hash
![Imgur](https://i.imgur.com/WuxLdS4.png)

# Risks and possible malicious actions
## Orphaned block (Uncommon, low risk)
What happens to results coming from an orphaned block? How do you verify the results? While this should be an uncommon situation, the participants doubting the organizer should always immediately verify the hash (preferrably by using TRG, because it will get data from the same node). This ensures that if the current chain is abandonned for another and the block generating the results is lost, the participants will already have verified the organizer's integrity.

## Malicious actor rejecting a block to alter the results (Very unlikely, high risk)
A malicious actor that successfuly mines a block at the time the organizer said he would generate the data could reject his block to alter the results. While this is very unlikely, someone that would reject the reward of a block to gain some advantage is likely to have a lot at stake in the event. Unless the event rewards the winner with something much better than a block reward, this should never happen.
