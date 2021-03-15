using System;
using Mutagen;
using Mutagen.Bethesda.Skyrim;
using System.Linq;
using Mutagen.Bethesda;

namespace MutagenSynthesisTask
{
    class Program
    {
        static void Main(string[] args)
        {
            // ➢ Use Mutagen to extract all of the statics from a given interior scene. After that,
            // find all single form-IDs of the base model for that static, and display them in
            // an array.

            // ➢ Use Synthesis to delete all of the navmeshes from an esm/ esp file
            var pathToMod = @"D:\SteamLibrary\steamapps\common\Skyrim\Data\Skyrim.esm";
            using var mod = SkyrimMod.CreateFromBinaryOverlay(pathToMod, SkyrimRelease.SkyrimLE);
            using var state = GameEnvironment.Typical.Skyrim(SkyrimRelease.SkyrimSE);
            foreach (var navContext in state.LoadOrder.PriorityOrder.ANavigationMesh().WinningContextOverrides(state.LinkCache))
            {
                var navMesh = navContext.Record;
                switch (navMesh)
                {
                    case ICellNavigationMeshGetter cellNav:
                        // some code
                        Console.WriteLine("This is a cellNav " + cellNav.Data.Parent.ToString());
                        break;
                    case IWorldspaceNavigationMeshGetter worldNav:
                        Console.WriteLine("This is a worldNav");
                        // some code
                        break;
                    default:
                        throw new NotImplementedException();
                }
                //navMesh.Data.
                //var data = navMesh.Data;
                //var triangles = data.Triangles;
                //Console.WriteLine(triangles.First().Vertices.ToString());
            }


            Console.WriteLine();


            // Get scene

            // Get statics within scene

            // Display all Ids of the base model for that static


            /*
             * 
             * 
             * foreach (var navContext in state.LoadOrder.PriorityOrder.ANavigationMesh().WinningContextOverrides(state.LinkCache))
                {
                    var navMesh = navContext.Record;
                    switch (navMesh)
                    {
                        case ICellNavigationMeshGetter cellNavGetter:
                            CellNavigationMesh cellNav = (CellNavigationMesh)navContext.GetOrAddAsOverride(state.PatchMod);
                            // Clear the triangles if they exist?
                            cellNav.Data?.Triangles.Clear();
                            break;
                        case IWorldspaceNavigationMeshGetter worldNav:
                            // some code            
                            break;
                        default:
                            throw new NotImplementedException();
                    }
                }
             */
        }
    }
}
