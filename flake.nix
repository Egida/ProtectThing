{
  description = "ProtectThing development environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            clang
            cmake
            boost
            nil
            nixd
          ];

        shellHook = ''
        export CMAKE_PREFIX_PATH="${pkgs.boost.dev}:$CMAKE_PREFIX_PATH"
        '';
        };
      }
    );
}
