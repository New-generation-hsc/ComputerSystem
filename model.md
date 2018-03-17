# Language Model : A Survey of the State-of-the-Art Technology

### introduction

- count-based
- continuous-space

### Problem

Neural Language Models(NLM) solves the problem of data sparsity of the n-gram model, by representing words as vectors(word embeddings)

Word emeddings obtained through NLMs exhibit the property whereby semantically close words are likewise close the induced vector space.

### Count-based language models

Using a statistical formulation to describe a LM is to construct the joint probability distribution of a sequence of words.

### Count-based drawbacks

- oov
- dependency
- syntactically and semantically similar

For example, one would wish from a good LM that it can recognize a sequence like "the cat is walking in the bedroom" to be syntactically and semantically similar to "a dog was running in the room", which cannot be provided by an n-gram model.


### Continuous-space lanuage model

- Feed-Forward Neural Network Based Models

The first neural approach to LM is a neural probabilistic language model.

fixed length context

- Recurrent Neural Network Based Models

### Advanced Models

Note that NLM are mostly word-level language models up to now. They are blind to subword information (e.g. morephemes)

subword-level LM and a character-wise NLM

outperforms word-level LSTM baselines with fewer parameters on lanuage with rich morphology.

a gated word-character recurrent LM is presented to address the same issue that information about morephemes such as prefix, root, and suffix is lost.

This gated word-character RNN LM utilizes both word-level and character-level inputs.


















