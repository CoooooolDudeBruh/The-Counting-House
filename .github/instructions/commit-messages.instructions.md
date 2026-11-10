---
applyTo: ".git/COMMIT_EDITMSG"
---
# STRICT CONVENTIONAL COMMITS FORMAT ENFORCEMENT
You are writing a Git commit message based on the staged code changes. Follow the Conventional Commits specification exactly using the structure: <type>(<scope>): <description>

# Rules
- Use imperative, present tense mood (e.g., "add", not "added" or "adds").
- Use all lowercase for the type and scope.
- Limit the first line (header) to 50 characters or less.
- Do not end the header line with a period.
- Separate the header from the body with a single blank line (if a body is necessary).

# Allowed Types
- feat: A new feature
- fix: A bug fix
- docs: Documentation changes only
- style: Changes that do not affect the meaning of the code (white-space, formatting)
- refactor: A code change that neither fixes a bug nor adds a feature
- perf: A code change that improves performance
- test: Adding missing tests or correcting existing tests
- build: Changes that affect the build system or external dependencies
- ci: Changes to CI configuration files and scripts
- chore: Other changes that don't modify src or test files

# Breaking Changes
- If a change introduces a breaking change, append a `!` after the type/scope (e.g., `feat!: rewrite auth`) and start the body with "BREAKING CHANGE: <description>".

# Output Requirement
- Output ONLY the raw commit message text. Do not wrap the message in markdown code blocks, and do not include any conversational preamble or explanations.
