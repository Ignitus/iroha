# Iroha reStructuredTest documentation

The purpose of this documentation is to convey design and architecture aspects of Iroha ledger in a structured approach, as well as operational side: how-tos, guides, and examples. Docs are accessible via ReadTheDocs website, and can be generated to a lot of formats, available in Sphinx. In order to contribute, one should to be familiar with [reStructuredTest](docutils.sourceforge.net/rst.html) syntax, and follow principles described in this file.

## Principles

 * modify only the contents of `image_assets` and `source` folders
 * if new section/file is added — it should be placed in the list of contents
 * if any new principle is added — it should be discussed in GitHub issues first, as an improvement proposal
 * reference images or assets using GitHub download link or an external service, since our localized docs can't use relative path to image assets or other resources

## Setup

 Generally, the docs are available via ReadTheDocs website. Although, to check the result locally, you can build them manually, by following this routine:

### Prerequisites

 * Python 2.7 or Python 3.3+, and pip installed
 * Installed [sphinx](http://www.sphinx-doc.org/en/stable/install.html)
 * Run `pip install -r requirements.txt` in docs/source

### Build steps

1. `cd docs/source`
1. `make html`

After that, the documentation is generated in html format in `_build` folder. You can check another formats on Sphinx website or just by typing `make`. In order to get familiar with the syntax of theme used in the project please go to their [demo website](https://sphinx-rtd-theme.readthedocs.io/en/latest/demo/demo.html)

### How to generate a version of docs for the target language

In essence, the flow of docs generation is described on the following page of [Sphinx documentation](http://www.sphinx-doc.org/en/stable/intl.html#id1). Shortly saying, there should be following steps performed:

1. `pip install sphinx-intl`
1. For each correction of an original english source test, `gettext` command should be invoked as here: `make gettext`
1. Update/create locale for docs invoking the sphinx-intl binary: `sphinx-intl update -p _build/gettext -l de -l ja`, which creates Japanese and German locale files.
1. Target project is generated by this command `make -e SPHINXOPTS="-D language='de'" html` (for German)

Got troubles with binary of `sphinx-intl` on Mac? Check if you have added it into PATH, usually it should be as following: `$PATH:$HOME/Library/Python/2.7/bin`.
 
 In the future, .po files should be published into https://weblate.org or similar platform, and the process of docs translation should be incorporated into open source community process.

## Contributors

The docs are supported by following contributors ([emoji key](https://github.com/kentcdodds/all-contributors#emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
| [<img src="https://avatars1.githubusercontent.com/u/11841667?s=460&v=4" width="100px;"/><br /><sub><b>Nikolay </b></sub>](https://github.com/neewy)<br />[📖](https://github.com/hyperledger/iroha/commits?author=neewy "Documentation") | [<img src="https://avatars3.githubusercontent.com/u/20982317?v=3&s=460" width="100px;"/><br /><sub>誠</sub>](https://github.com/takemiyamakoto)<br />🔧
| :---: | :---: |
<!-- ALL-CONTRIBUTORS-LIST:END -->
