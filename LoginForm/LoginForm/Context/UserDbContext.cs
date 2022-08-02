using Microsoft.EntityFrameworkCore;

namespace LoginForm.Context
{
    public class UserDbContext:DbContext

    {
        public UserDbContext(DbContextOptions options) : base(options)
        {

        }
        DbSet<User> Users { get; set; }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<User>().HasData(
                new User() { ID = 1, Username = "a", Password = "abc" },
                new User() { ID = 2, Username = "b", Password = "bcd" },
                new User() { ID = 3, Username = "c", Password = "cde" });
        }
    }
}
